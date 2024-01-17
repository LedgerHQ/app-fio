#include "diffieHellman.h"
#include "os_math.h"

//---------------------------- UTILS ---------------------------------------

static const uint8_t BASE64[64] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                                   'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                                   'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                                   'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                                   '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

static void base64EncBlock(uint8_t in[3], uint8_t out[4]) {
    out[0] = BASE64[(in[0] / 0x04) & 0x3F];
    out[1] = BASE64[(in[0] * 0x10 + in[1] / 0x10) & 0x3F];
    out[2] = BASE64[(in[1] * 0x04 + in[2] / 0x40) & 0x3F];
    out[3] = BASE64[in[2] & 0x3F];
}

// Returns number of bytes written
// Move unencoded part of inBuffer to the beginning and sets inSize accordingly
static size_t base64EncWholeBlocks(uint8_t* inBuffer,
                                   uint8_t* inSize,
                                   uint8_t* outBuffer,
                                   size_t outSize) {
    uint8_t processedBlocks = 0;
    while (1) {
        // We cannot process whole block
        if (*inSize < BASE64_IN_BLOCK_SIZE * (processedBlocks + 1)) {
            // move unread inBuffer data to beginning and set new inSize
            *inSize -= BASE64_IN_BLOCK_SIZE * processedBlocks;
            memmove(inBuffer, inBuffer + BASE64_IN_BLOCK_SIZE * processedBlocks, *inSize);
            break;
        }

        // process one block, inBuffer + BASE64_IN_BLOCK_SIZE*processedBlocks and next two values
        // exist
        ASSERT(outSize >= BASE64_OUT_BLOCK_SIZE * (processedBlocks + 1));
        base64EncBlock(inBuffer + BASE64_IN_BLOCK_SIZE * processedBlocks,
                       outBuffer + BASE64_OUT_BLOCK_SIZE * processedBlocks);
        processedBlocks++;
    }
    return BASE64_OUT_BLOCK_SIZE * processedBlocks;
}

static size_t processDHOneBlockFromCache(dh_context_t* ctx,
                                         const dh_aes_key_t* aes_key,
                                         uint8_t* outBuffer,
                                         size_t outSize) {
    ASSERT(ctx->cacheLength == CX_AES_BLOCK_SIZE);
    STATIC_ASSERT(SIZEOF(ctx->IV) == CX_AES_BLOCK_SIZE, "Incompatible IV size");

    // We work in CBC mode
    // 1. IV xor plaintext
    for (size_t i = 0; i < CX_AES_BLOCK_SIZE; i++) {
        ctx->cache[i] ^= ctx->IV[i];
    }

    // 2. encrypt the result to obtain cyphertext 3. use cyphertext as new IV
    cx_err_t err = cx_aes_enc_block(&aes_key->aesKey, ctx->cache, ctx->IV);
    ASSERT(err == CX_OK);

    // append cyphertext (not base64 encrypted) to hmac and clear cache
    err = cx_hmac_update((cx_hmac_t*) &ctx->hmacCtx, ctx->IV, CX_AES_BLOCK_SIZE);
    ASSERT(err == CX_OK);
    explicit_bzero(ctx->cache, SIZEOF(ctx->cache));
    ctx->cacheLength = 0;

    // base64 encode
    ASSERT(ctx->base64EncodingCacheLen < BASE64_IN_BLOCK_SIZE);
    STATIC_ASSERT(SIZEOF(ctx->base64EncodingCache) >= BASE64_IN_BLOCK_SIZE + CX_AES_BLOCK_SIZE,
                  "Cache too small");
    memmove(ctx->base64EncodingCache + ctx->base64EncodingCacheLen, ctx->IV, CX_AES_BLOCK_SIZE);
    ctx->base64EncodingCacheLen += CX_AES_BLOCK_SIZE;
    return base64EncWholeBlocks(ctx->base64EncodingCache,
                                &ctx->base64EncodingCacheLen,
                                outBuffer,
                                outSize);
}

//---------------------------- DH ENCODING ---------------------------------------

__noinline_due_to_stack__ void dh_init_aes_key(dh_aes_key_t* dhKey,
                                               const bip44_path_t* pathSpec,
                                               const public_key_t* publicKey) {
    TRACE_STACK_USAGE();
    private_key_t privateKey;
    unsigned char basicSecret[32];
    unsigned char secret[SHA_512_SIZE];
    uint8_t K[SHA_512_SIZE];

    TRACE("dh_init_aesKey");
    BEGIN_TRY {
        TRY {
            TRACE_STACK_USAGE();
            derivePrivateKey(pathSpec, &privateKey);

            // this is how it is done...
            cx_err_t err = cx_ecdh_no_throw(&privateKey,
                                            CX_ECDH_X,
                                            publicKey->W,
                                            publicKey->W_len,
                                            basicSecret,
                                            SIZEOF(basicSecret));
            ASSERT(err == CX_OK);
            sha_512_hash(basicSecret, SIZEOF(basicSecret), secret, SIZEOF(secret));
            sha_512_hash(secret, SIZEOF(secret), K, SIZEOF(K));

            // First DH_AES_SECRET_SIZE bytes are used to compute shared secret, then DH_KM_SIZE are
            // used as Km for HMAC calculation
            STATIC_ASSERT(SIZEOF(K) == DH_AES_SECRET_SIZE + DH_KM_SIZE, "Incompatible types");
            cx_aes_init_key_no_throw(K, DH_AES_SECRET_SIZE, &dhKey->aesKey);
            STATIC_ASSERT(SIZEOF(dhKey->km) == DH_KM_SIZE, "Incompatible types");
            memmove(dhKey->km, K + DH_AES_SECRET_SIZE, DH_KM_SIZE);
            dhKey->initialized_magic = DH_AES_KEY_INITIALIZED_MAGIC;
        }
        FINALLY {
            explicit_bzero(&privateKey, sizeof(privateKey));
            explicit_bzero(basicSecret, SIZEOF(basicSecret));
            explicit_bzero(secret, SIZEOF(secret));
            explicit_bzero(K, SIZEOF(K));
        }
    }
    END_TRY;
}

__noinline_due_to_stack__ size_t dh_encode_init(dh_context_t* ctx,
                                                const dh_aes_key_t* aes_key,
                                                const uint8_t* iv,
                                                size_t ivSize,
                                                uint8_t* outBuffer,
                                                size_t outSize) {
    TRACE_STACK_USAGE();
    TRACE("dh_encode_init");

    ASSERT(ivSize == SIZEOF(ctx->IV));
    ASSERT(aes_key->initialized_magic == DH_AES_KEY_INITIALIZED_MAGIC);

    ctx->cacheLength = 0;
    explicit_bzero(ctx->cache, SIZEOF(ctx->cache));
    ctx->base64EncodingCacheLen = 0;
    explicit_bzero(ctx->base64EncodingCache, SIZEOF(ctx->base64EncodingCache));
    memcpy(ctx->IV, iv, SIZEOF(ctx->IV));

    explicit_bzero(&ctx->hmacCtx, SIZEOF(ctx->hmacCtx));
    cx_err_t err = cx_hmac_sha256_init_no_throw(&ctx->hmacCtx, aes_key->km, SIZEOF(aes_key->km));
    ASSERT(err == CX_OK);
    err = cx_hmac_update((cx_hmac_t*) &ctx->hmacCtx, iv, ivSize);
    ASSERT(err == CX_OK);

    ctx->initialized_magic = HASH_CONTEXT_INITIALIZED_MAGIC;

    // Base64 We encode IV
    STATIC_ASSERT(SIZEOF(ctx->base64EncodingCache) >= SIZEOF(ctx->IV), "Cache too small");
    memcpy(ctx->base64EncodingCache, ctx->IV, SIZEOF(ctx->IV));
    ctx->base64EncodingCacheLen = SIZEOF(ctx->IV);
    return base64EncWholeBlocks(ctx->base64EncodingCache,
                                &ctx->base64EncodingCacheLen,
                                outBuffer,
                                outSize);
}

__noinline_due_to_stack__ size_t dh_encode_append(dh_context_t* ctx,
                                                  const dh_aes_key_t* aes_key,
                                                  const uint8_t* inBuffer,
                                                  size_t inSize,
                                                  uint8_t* outBuffer,
                                                  size_t outSize) {
    TRACE("dh_encode_append");
    TRACE_STACK_USAGE();

    ASSERT(inSize < BUFFER_SIZE_PARANOIA);
    ASSERT(ctx->initialized_magic == HASH_CONTEXT_INITIALIZED_MAGIC);
    ASSERT(aes_key->initialized_magic == DH_AES_KEY_INITIALIZED_MAGIC);
    ASSERT(ctx->cacheLength < CX_AES_BLOCK_SIZE);
    STATIC_ASSERT(SIZEOF(ctx->cache) >= CX_AES_BLOCK_SIZE, "dh_context_t->cache too small");

    size_t processedInput = 0;
    size_t written = 0;
    while (1) {
        // fill ctx->buffer
        size_t to_read = MIN(CX_AES_BLOCK_SIZE - ctx->cacheLength, inSize - processedInput);
        memcpy(ctx->cache + ctx->cacheLength, inBuffer + processedInput, to_read);
        ctx->cacheLength += to_read;
        processedInput += to_read;

        // if block is only partially filled, we finish encoding, the data was read to cache
        // this means that there was not enough input to fill the block
        if (ctx->cacheLength < CX_AES_BLOCK_SIZE) {
            TRACE("Block not full");
            break;
        }

        written += processDHOneBlockFromCache(ctx, aes_key, outBuffer + written, outSize - written);
    }

    TRACE("Leaving dh_encode_append, written: %d", (int) written);
    return written;
}

__noinline_due_to_stack__ size_t dh_encode_finalize(dh_context_t* ctx,
                                                    const dh_aes_key_t* aes_key,
                                                    uint8_t* outBuffer,
                                                    size_t outSize) {
    TRACE("dh_encode_finalize");

    ASSERT(ctx->initialized_magic == HASH_CONTEXT_INITIALIZED_MAGIC);
    ASSERT(aes_key->initialized_magic == DH_AES_KEY_INITIALIZED_MAGIC);
    ASSERT(ctx->cacheLength < CX_AES_BLOCK_SIZE);
    TRACE("Cache length %d", (int) ctx->cacheLength);
    TRACE_BUFFER(ctx->cache, ctx->cacheLength);

    // fill the last cache block with integers equal to number of elements missing
    // if the next block is empty we create a block full of 0x10 (CX_AES_BLOCK_SIZE)
    STATIC_ASSERT(SIZEOF(ctx->cache) >= CX_AES_BLOCK_SIZE, "dh_context_t->cache too small");
    uint8_t fillValue = CX_AES_BLOCK_SIZE - ctx->cacheLength;
    for (size_t i = ctx->cacheLength; i < CX_AES_BLOCK_SIZE; i++) {
        ctx->cache[i] = fillValue;
    }
    ctx->cacheLength = CX_AES_BLOCK_SIZE;

    uint8_t written = 0;
    written += processDHOneBlockFromCache(ctx, aes_key, outBuffer + written, outSize - written);

    // finalize hmac and append base64 encode it and append to cyphertext
    size_t hmacOutSize = SIZEOF(ctx->base64EncodingCache) - ctx->base64EncodingCacheLen;
    cx_err_t err = cx_hmac_final((cx_hmac_t*) &ctx->hmacCtx,
                                 ctx->base64EncodingCache + ctx->base64EncodingCacheLen,
                                 &hmacOutSize);
    ASSERT(err == CX_OK);
    ASSERT(hmacOutSize == DH_HMAC_SIZE);
    ctx->base64EncodingCacheLen += DH_HMAC_SIZE;
    written += base64EncWholeBlocks(ctx->base64EncodingCache,
                                    &ctx->base64EncodingCacheLen,
                                    outBuffer + written,
                                    outSize - written);

    // the last base64 encoding block
    uint8_t lastBlock[3] = {0, 0, 0};
    switch (ctx->base64EncodingCacheLen) {
        case 0:
            break;
        case 1:
            ASSERT(outSize >= written + BASE64_OUT_BLOCK_SIZE);
            lastBlock[0] = ctx->base64EncodingCache[0];
            base64EncBlock(lastBlock, outBuffer + written);
            *(outBuffer + written + 2) = '=';
            *(outBuffer + written + 3) = '=';
            written += BASE64_OUT_BLOCK_SIZE;
            break;
        case 2:
            ASSERT(outSize >= written + BASE64_OUT_BLOCK_SIZE);
            lastBlock[0] = ctx->base64EncodingCache[0];
            lastBlock[1] = ctx->base64EncodingCache[1];
            base64EncBlock(lastBlock, outBuffer + written);
            *(outBuffer + written + 3) = '=';
            written += BASE64_OUT_BLOCK_SIZE;
            break;
        default:
            ASSERT(false);
    }
    return written;
}

__noinline_due_to_stack__ size_t dh_encode(bip44_path_t* pathSpec,
                                           public_key_t* publicKey,
                                           const uint8_t* iv,
                                           size_t ivSize,
                                           const uint8_t* inBuffer,
                                           size_t inSize,
                                           uint8_t* outBuffer,
                                           size_t outSize) {
    dh_aes_key_t key;
    TRACE("dh_encode");

    ASSERT(inSize < BUFFER_SIZE_PARANOIA);

    size_t written = 0;

    BEGIN_TRY {
        TRY {
            TRACE_STACK_USAGE();
            dh_init_aes_key(&key, pathSpec, publicKey);

            dh_context_t ctx;
            written +=
                dh_encode_init(&ctx, &key, iv, ivSize, outBuffer + written, outSize - written);
            TRACE("Init: written %d", written);
            TRACE_BUFFER(outBuffer, written);
            written += dh_encode_append(&ctx,
                                        &key,
                                        inBuffer,
                                        inSize,
                                        outBuffer + written,
                                        outSize - written);
            TRACE("Append: written %d", written);
            TRACE_BUFFER(outBuffer, written);
            written += dh_encode_finalize(&ctx, &key, outBuffer + written, outSize - written);
            TRACE("Finalize: written %d", written);
            TRACE_BUFFER(outBuffer, written);
        }
        FINALLY {
            explicit_bzero(&key, sizeof(key));
        }
    }
    END_TRY;

    return written;
}

__noinline_due_to_stack__ static void validateHmac(dh_aes_key_t* aes_key,
                                                   const uint8_t* buffer,
                                                   size_t inSize) {
    VALIDATE(inSize >= DH_AES_IV_SIZE + CX_AES_BLOCK_SIZE + DH_HMAC_SIZE, ERR_INVALID_DATA);

    cx_hmac_sha256_t hmac;
    cx_err_t err = cx_hmac_sha256_init_no_throw(&hmac, aes_key->km, SIZEOF(aes_key->km));
    ASSERT(err == CX_OK);
    err = cx_hmac_update((cx_hmac_t*) &hmac, buffer, inSize - DH_HMAC_SIZE);
    ASSERT(err == CX_OK);
    uint8_t hmacBuf[DH_HMAC_SIZE];
    size_t outLen = SIZEOF(hmacBuf);
    err = cx_hmac_final((cx_hmac_t*) &hmac, hmacBuf, &outLen);
    ASSERT(err == CX_OK);
    ASSERT(outLen == DH_HMAC_SIZE);
    VALIDATE(!memcmp(hmacBuf, buffer + inSize - DH_HMAC_SIZE, DH_HMAC_SIZE), ERR_INVALID_HMAC);
}

__noinline_due_to_stack__ size_t dh_decode(bip44_path_t* pathSpec,
                                           public_key_t* publicKey,
                                           uint8_t* buffer,
                                           size_t inSize) {
    VALIDATE(inSize >= DH_AES_IV_SIZE + CX_AES_BLOCK_SIZE + DH_HMAC_SIZE, ERR_INVALID_DATA);
    VALIDATE(inSize % CX_AES_BLOCK_SIZE == 0, ERR_INVALID_DATA);

    size_t read =
        DH_AES_IV_SIZE;  // we do not decode IV, this also creates a buffer so we can decode inplace
    size_t written = 0;
    dh_aes_key_t aes_key;
    BEGIN_TRY {
        TRY {
            dh_init_aes_key(&aes_key, pathSpec, publicKey);

            // validate HMAC
            validateHmac(&aes_key, buffer, inSize);
            TRACE("HMAC validation succesfull.");

            // initiate DH decryptions
            uint8_t IV[CX_AES_BLOCK_SIZE];
            memcpy(IV, buffer, SIZEOF(IV));

            for (; read < inSize - DH_HMAC_SIZE; read += CX_AES_BLOCK_SIZE) {
                // 1. Decode next block
                ASSERT(read - written == CX_AES_BLOCK_SIZE);
                cx_err_t err = cx_aes_dec_block(&aes_key.aesKey, buffer + read, buffer + written);
                ASSERT(err == CX_OK);
                // 2. XOR with IV
                for (size_t i = 0; i < CX_AES_BLOCK_SIZE; i++) {
                    buffer[written + i] ^= IV[i];
                }
                // 3. Cyphertext is the new IV ... we do not care that we copy part of HMAC in last
                // iteration here
                memcpy(IV, buffer + read, CX_AES_BLOCK_SIZE);
                written += CX_AES_BLOCK_SIZE;
            }
        }
        FINALLY {
            explicit_bzero(&aes_key, sizeof(aes_key));
        }
    }
    END_TRY;

    TRACE("Finishing decription, written:%d, lastCharacter:%d", written, buffer[written - 1]);
    // Calculate resulting length based on the last decoded value
    ASSERT(written != 0);
    ASSERT(written >= buffer[written - 1]);
    return written - buffer[written - 1];
}
