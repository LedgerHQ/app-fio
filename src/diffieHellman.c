#include "diffieHellman.h"
#include "os_math.h"

// This is crypto module, we do not want to jump from it
// To avoid mistakes, we undef most common macros we do not want to use
#undef ASSERT
#undef THROW
#undef VALIDATE

//---------------------------- UTILS ---------------------------------------

static const uint8_t BASE64[64] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                                   'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                                   'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                                   'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                                   '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

static void base64EncBlock(uint8_t in[BASE64_IN_BLOCK_SIZE], uint8_t out[BASE64_OUT_BLOCK_SIZE]) {
    out[0] = BASE64[(in[0] / 0x04) & 0x3F];
    out[1] = BASE64[(in[0] * 0x10 + in[1] / 0x10) & 0x3F];
    out[2] = BASE64[(in[1] * 0x04 + in[2] / 0x40) & 0x3F];
    out[3] = BASE64[in[2] & 0x3F];
}

// Base64 encodes as many block as possible.
// Move unencoded part of inBuffer to the beginning and sets inSize accordingly
static WARN_UNUSED_RESULT uint16_t base64EncWholeBlocks(uint8_t *inBuffer,
                                                        uint8_t *inSize,
                                                        uint8_t *outBuffer,
                                                        uint16_t *outSize) {
    // Variable for CRYPTO_ error handling macros
    uint16_t error_to_return = ERR_ASSERT;

    uint8_t processedBlocks = 0;
    while (1) {
        // We cannot process whole block
        if (*inSize < BASE64_IN_BLOCK_SIZE * (processedBlocks + 1)) {
            // move unread inBuffer data to beginning and set new inSize
            *inSize -= BASE64_IN_BLOCK_SIZE * processedBlocks;
            memmove(inBuffer, inBuffer + BASE64_IN_BLOCK_SIZE * processedBlocks, *inSize);
            break;
        }

        // process one block
        CRYPTO_ASSERT(*outSize >= BASE64_OUT_BLOCK_SIZE * (processedBlocks + 1));
        base64EncBlock(inBuffer + BASE64_IN_BLOCK_SIZE * processedBlocks,
                       outBuffer + BASE64_OUT_BLOCK_SIZE * processedBlocks);
        processedBlocks++;
    }
    *outSize = BASE64_OUT_BLOCK_SIZE * processedBlocks;
    error_to_return = SUCCESS;
end:
    return error_to_return;
}

// Encodes one block from cache using AES key
// Move unencoded part of inBuffer to the beginning and sets inSize accordingly
static WARN_UNUSED_RESULT uint16_t processDHOneBlockFromCache(dh_context_t *ctx,
                                                              const dh_aes_key_t *aesKey,
                                                              uint8_t *outBuffer,
                                                              uint16_t *outSize) {
    // Variable for CRYPTO_ error handling macros
    uint16_t error_to_return = ERR_ASSERT;

    // precondition sanity check
    CRYPTO_ASSERT(ctx->cacheLength == CX_AES_BLOCK_SIZE);
    STATIC_ASSERT(SIZEOF(ctx->IV) == CX_AES_BLOCK_SIZE, "Incompatible IV size");

    // We work in CBC mode
    // 1. IV xor plaintext
    for (uint16_t i = 0; i < CX_AES_BLOCK_SIZE; i++) {
        ctx->cache[i] ^= ctx->IV[i];
    }

    // 2. encrypt the result to obtain cyphertext 3. use cyphertext as new IV
    CRYPTO_CX_CHECK(cx_aes_enc_block(&aesKey->aesKey, ctx->cache, ctx->IV));

    // append cyphertext (not base64 encrypted) to hmac and clear cache
    CRYPTO_CX_CHECK(cx_hmac_update((cx_hmac_t *) &ctx->hmacCtx, ctx->IV, CX_AES_BLOCK_SIZE));
    explicit_bzero(ctx->cache, SIZEOF(ctx->cache));
    ctx->cacheLength = 0;

    // base64 encode
    // sanity check, we expect that cache does not contain whole block first
    CRYPTO_ASSERT(ctx->base64EncodingCacheLen < BASE64_IN_BLOCK_SIZE);
    STATIC_ASSERT(SIZEOF(ctx->base64EncodingCache) >= BASE64_IN_BLOCK_SIZE + CX_AES_BLOCK_SIZE,
                  "Cache too small");
    memmove(ctx->base64EncodingCache + ctx->base64EncodingCacheLen, ctx->IV, CX_AES_BLOCK_SIZE);
    ctx->base64EncodingCacheLen += CX_AES_BLOCK_SIZE;
    // This also sets outSize as desired
    CRYPTO_FORWARD_ERROR(base64EncWholeBlocks(ctx->base64EncodingCache,
                                              &ctx->base64EncodingCacheLen,
                                              outBuffer,
                                              outSize));
    error_to_return = SUCCESS;
end:  // CRYPTO_ macros jump here in case of error
    return error_to_return;
}

//---------------------------- DH ENCODING ---------------------------------------

__noinline_due_to_stack__ WARN_UNUSED_RESULT uint16_t
dh_init_aes_key(dh_aes_key_t *dhKey, const bip44_path_t *pathSpec, const public_key_t *publicKey) {
    // Crypto assets to be cleared
    private_key_t privateKey;
    unsigned char basicSecret[32];
    unsigned char secret[SHA_512_SIZE];
    uint8_t K[SHA_512_SIZE];
    explicit_bzero(&privateKey, SIZEOF(privateKey));
    explicit_bzero(basicSecret, SIZEOF(basicSecret));
    explicit_bzero(secret, SIZEOF(secret));
    explicit_bzero(K, SIZEOF(K));
    explicit_bzero(dhKey, SIZEOF(*dhKey));

    // Variable for CRYPTO_ error handling macros
    uint16_t error_to_return = ERR_ASSERT;

    TRACE_STACK_USAGE();
    TRACE("dh_init_aesKey");

    CRYPTO_FORWARD_ERROR(derivePrivateKey(pathSpec, &privateKey));

    // Derive aes key.
    CRYPTO_CX_CHECK(cx_ecdh_no_throw(&privateKey,
                                     CX_ECDH_X,
                                     publicKey->W,
                                     publicKey->W_len,
                                     basicSecret,
                                     SIZEOF(basicSecret)));
    CRYPTO_CX_CHECK(sha_512_hash(basicSecret, SIZEOF(basicSecret), secret, SIZEOF(secret)));
    CRYPTO_CX_CHECK(sha_512_hash(secret, SIZEOF(secret), K, SIZEOF(K)));

    // First DH_AES_SECRET_SIZE bytes are used to compute shared secret, then DH_KM_SIZE are
    // used as Km for HMAC calculation
    STATIC_ASSERT(SIZEOF(K) == DH_AES_SECRET_SIZE + DH_KM_SIZE, "Incompatible types");
    CRYPTO_CX_CHECK(cx_aes_init_key_no_throw(K, DH_AES_SECRET_SIZE, &dhKey->aesKey));

    STATIC_ASSERT(SIZEOF(dhKey->km) == DH_KM_SIZE, "Incompatible types");
    memmove(dhKey->km, K + DH_AES_SECRET_SIZE, DH_KM_SIZE);

    error_to_return = SUCCESS;
end:  // CRYPTO_ macros jump here in case of error
    if (error_to_return != SUCCESS) {
        explicit_bzero(dhKey, SIZEOF(*dhKey));
    }
    explicit_bzero(&privateKey, SIZEOF(privateKey));
    explicit_bzero(basicSecret, SIZEOF(basicSecret));
    explicit_bzero(secret, SIZEOF(secret));
    explicit_bzero(K, SIZEOF(K));
    return error_to_return;
}

__noinline_due_to_stack__ WARN_UNUSED_RESULT uint16_t dh_encode_init(dh_context_t *ctx,
                                                                     const bip44_path_t *pathSpec,
                                                                     const public_key_t *publicKey,
                                                                     const uint8_t *iv,
                                                                     uint16_t ivSize,
                                                                     uint8_t *outBuffer,
                                                                     uint16_t *outSize) {
    // Crypto assets to be cleared
    dh_aes_key_t aesKey;
    explicit_bzero(&aesKey, SIZEOF(aesKey));

    // Variable for CRYPTO_ error handling macros
    uint16_t error_to_return = ERR_ASSERT;

    TRACE_STACK_USAGE();
    TRACE("dh_encode_init");

    STATIC_ASSERT(SIZEOF(ctx->IV) == CX_AES_BLOCK_SIZE, "Unexpected IV length");
    CRYPTO_ASSERT(ivSize == SIZEOF(ctx->IV));

    // Initialize DH context
    ctx->cacheLength = 0;
    explicit_bzero(ctx->cache, SIZEOF(ctx->cache));
    ctx->base64EncodingCacheLen = 0;
    explicit_bzero(ctx->base64EncodingCache, SIZEOF(ctx->base64EncodingCache));
    memcpy(ctx->IV, iv, SIZEOF(ctx->IV));

    // Compute AES key and forward error
    CRYPTO_FORWARD_ERROR(dh_init_aes_key(&aesKey, pathSpec, publicKey));

    explicit_bzero(&ctx->hmacCtx, SIZEOF(ctx->hmacCtx));
    CRYPTO_CX_CHECK(cx_hmac_sha256_init_no_throw(&ctx->hmacCtx, aesKey.km, SIZEOF(aesKey.km)));
    CRYPTO_CX_CHECK(cx_hmac_update((cx_hmac_t *) &ctx->hmacCtx, iv, ivSize));

    // Base64 We encode IV
    STATIC_ASSERT(SIZEOF(ctx->base64EncodingCache) >= SIZEOF(ctx->IV), "Cache too small");
    memcpy(ctx->base64EncodingCache, ctx->IV, SIZEOF(ctx->IV));
    ctx->base64EncodingCacheLen = SIZEOF(ctx->IV);

    ctx->initialized_magic = HASH_CONTEXT_INITIALIZED_MAGIC;
    // Context initialization finished

    // This also sets outSize as desired.
    CRYPTO_FORWARD_ERROR(base64EncWholeBlocks(ctx->base64EncodingCache,
                                              &ctx->base64EncodingCacheLen,
                                              outBuffer,
                                              outSize));
    error_to_return = SUCCESS;
end:
    // CX_CHECK macro jumps her in case of an error. Cleanup.
    explicit_bzero(&aesKey, SIZEOF(aesKey));
    return error_to_return;
}

__noinline_due_to_stack__ WARN_UNUSED_RESULT uint16_t
dh_encode_append(dh_context_t *ctx,
                 const bip44_path_t *pathSpec,
                 const public_key_t *publicKey,
                 const uint8_t *inBuffer,
                 uint16_t inSize,
                 uint8_t *outBuffer,
                 uint16_t *outSize) {
    // Crypto assets to be cleared
    dh_aes_key_t aesKey;
    explicit_bzero(&aesKey, SIZEOF(aesKey));

    // Variable for CRYPTO_ error handling macros
    uint16_t error_to_return = ERR_ASSERT;

    TRACE("dh_encode_append");
    TRACE_STACK_USAGE();

    // sanity checks
    CRYPTO_ASSERT(inSize < BUFFER_SIZE_PARANOIA);
    CRYPTO_ASSERT(ctx->initialized_magic == HASH_CONTEXT_INITIALIZED_MAGIC);
    CRYPTO_ASSERT(ctx->cacheLength < CX_AES_BLOCK_SIZE);
    STATIC_ASSERT(SIZEOF(ctx->cache) >= CX_AES_BLOCK_SIZE, "dh_context_t->cache too small");

    // Compute AES key and forward error
    CRYPTO_FORWARD_ERROR(dh_init_aes_key(&aesKey, pathSpec, publicKey));

    uint16_t processedInput = 0;
    uint16_t written = 0;
    while (1) {
        // fill ctx->buffer
        CRYPTO_ASSERT(inSize >= processedInput);
        uint16_t to_read = MIN(CX_AES_BLOCK_SIZE - ctx->cacheLength, inSize - processedInput);
        memcpy(ctx->cache + ctx->cacheLength, inBuffer + processedInput, to_read);
        ctx->cacheLength += to_read;
        processedInput += to_read;

        // if block is only partially filled, we finish encoding, the data was read to cache
        // this means that there was not enough input to fill the block
        if (ctx->cacheLength < CX_AES_BLOCK_SIZE) {
            TRACE("Block not full");
            break;
        }

        uint16_t remainingBufferLength = *outSize - written;  // remaining buffer
        CRYPTO_FORWARD_ERROR(
            processDHOneBlockFromCache(ctx, &aesKey, outBuffer + written, &remainingBufferLength));
        written += remainingBufferLength;
    }
    TRACE("Leaving dh_encode_append, written: %d", (int) written);

    // Cleanup
    *outSize = written;
    error_to_return = SUCCESS;
end:
    explicit_bzero(&aesKey, SIZEOF(aesKey));
    return error_to_return;
}

__noinline_due_to_stack__ WARN_UNUSED_RESULT uint16_t
dh_encode_finalize(dh_context_t *ctx,
                   const bip44_path_t *pathSpec,
                   const public_key_t *publicKey,
                   uint8_t *outBuffer,
                   uint16_t *outSize) {
    // Crypto assets to be cleared
    dh_aes_key_t aesKey;
    explicit_bzero(&aesKey, SIZEOF(aesKey));
    // ctx->base64EncodingCache needs to be cleared as it will contain sensitive HMAC

    // Variable for CRYPTO_ error handling macros
    uint16_t error_to_return = ERR_ASSERT;

    TRACE("dh_encode_finalize");
    TRACE_STACK_USAGE();

    // sanity checks
    CRYPTO_ASSERT(ctx->initialized_magic == HASH_CONTEXT_INITIALIZED_MAGIC);
    CRYPTO_ASSERT(ctx->cacheLength < CX_AES_BLOCK_SIZE);
    STATIC_ASSERT(SIZEOF(ctx->cache) >= CX_AES_BLOCK_SIZE, "dh_context_t->cache too small");
    TRACE_BUFFER(ctx->cache, ctx->cacheLength);

    // Compute AES key
    CRYPTO_FORWARD_ERROR(dh_init_aes_key(&aesKey, pathSpec, publicKey));

    // Fill the last cache block with integers equal to number of elements missing.
    // If the next block is empty we create a block full of 0x10 (CX_AES_BLOCK_SIZE)
    STATIC_ASSERT(SIZEOF(ctx->cache) >= CX_AES_BLOCK_SIZE, "dh_context_t->cache too small");
    uint8_t fillValue = CX_AES_BLOCK_SIZE - ctx->cacheLength;
    for (uint16_t i = ctx->cacheLength; i < CX_AES_BLOCK_SIZE; i++) {
        ctx->cache[i] = fillValue;
    }
    ctx->cacheLength = CX_AES_BLOCK_SIZE;

    uint8_t written = 0;

    // Encode last block
    {
        uint16_t remainingBufferLength = *outSize - written;  // remaining buffer
        CRYPTO_FORWARD_ERROR(
            processDHOneBlockFromCache(ctx, &aesKey, outBuffer + written, &remainingBufferLength));
        written += remainingBufferLength;
    }

    // finalize hmac and append base64 encode it and append to cyphertext
    {
        size_t hmacOutSize = SIZEOF(ctx->base64EncodingCache) - ctx->base64EncodingCacheLen;
        CRYPTO_CX_CHECK(cx_hmac_final((cx_hmac_t *) &ctx->hmacCtx,
                                      ctx->base64EncodingCache + ctx->base64EncodingCacheLen,
                                      &hmacOutSize));
        CRYPTO_ASSERT(hmacOutSize == DH_HMAC_SIZE);
        ctx->base64EncodingCacheLen += DH_HMAC_SIZE;
    }

    // Encode cache content
    {
        uint16_t remainingBufferLength = *outSize - written;  // remaining buffer
        CRYPTO_FORWARD_ERROR(base64EncWholeBlocks(ctx->base64EncodingCache,
                                                  &ctx->base64EncodingCacheLen,
                                                  outBuffer + written,
                                                  &remainingBufferLength));
        written += remainingBufferLength;
    }

    // the last base64 encoding block
    uint8_t lastBlock[3] = {0, 0, 0};
    switch (ctx->base64EncodingCacheLen) {
        case 0:
            break;
        case 1:
            CRYPTO_ASSERT(*outSize >= written + BASE64_OUT_BLOCK_SIZE);
            STATIC_ASSERT(BASE64_OUT_BLOCK_SIZE >= 3, "BASE64_OUT_BLOCK_SIZE too small");
            lastBlock[0] = ctx->base64EncodingCache[0];
            base64EncBlock(lastBlock, outBuffer + written);
            *(outBuffer + written + 2) = '=';
            *(outBuffer + written + 3) = '=';
            written += BASE64_OUT_BLOCK_SIZE;
            break;
        case 2:
            CRYPTO_ASSERT(*outSize >= written + BASE64_OUT_BLOCK_SIZE);
            STATIC_ASSERT(BASE64_OUT_BLOCK_SIZE >= 3, "BASE64_OUT_BLOCK_SIZE too small");
            lastBlock[0] = ctx->base64EncodingCache[0];
            lastBlock[1] = ctx->base64EncodingCache[1];
            base64EncBlock(lastBlock, outBuffer + written);
            *(outBuffer + written + 3) = '=';
            written += BASE64_OUT_BLOCK_SIZE;
            break;
        default:
            CRYPTO_ASSERT(false);
    }

    *outSize = written;
    error_to_return = SUCCESS;
end:
    explicit_bzero(&aesKey, SIZEOF(aesKey));
    explicit_bzero(ctx->base64EncodingCache, SIZEOF(ctx->base64EncodingCache));
    return error_to_return;
}

#ifdef DEVEL
__noinline_due_to_stack__ WARN_UNUSED_RESULT uint16_t dh_encode(bip44_path_t *pathSpec,
                                                                public_key_t *publicKey,
                                                                const uint8_t *iv,
                                                                uint16_t ivSize,
                                                                const uint8_t *inBuffer,
                                                                uint16_t inSize,
                                                                uint8_t *outBuffer,
                                                                uint16_t *outSize) {
    // Variable for CRYPTO_ error handling macros
    uint16_t error_to_return = ERR_ASSERT;

    TRACE("dh_encode");
    CRYPTO_ASSERT(inSize < BUFFER_SIZE_PARANOIA);

    dh_context_t ctx;

    uint16_t written = 0;
    uint16_t remaining = *outSize - written;
    CRYPTO_FORWARD_ERROR(
        dh_encode_init(&ctx, pathSpec, publicKey, iv, ivSize, outBuffer + written, &remaining));
    written += remaining;

    remaining = *outSize - written;
    CRYPTO_FORWARD_ERROR(dh_encode_append(&ctx,
                                          pathSpec,
                                          publicKey,
                                          inBuffer,
                                          inSize,
                                          outBuffer + written,
                                          &remaining));
    written += remaining;

    remaining = *outSize - written;
    CRYPTO_FORWARD_ERROR(
        dh_encode_finalize(&ctx, pathSpec, publicKey, outBuffer + written, &remaining));
    written += remaining;

    *outSize = written;
    error_to_return = SUCCESS;
end:
    return error_to_return;
}
#endif

__noinline_due_to_stack__ static WARN_UNUSED_RESULT uint16_t validateHmac(dh_aes_key_t *aesKey,
                                                                          const uint8_t *buffer,
                                                                          uint16_t inSize) {
    // Variable for CRYPTO_ error handling macros
    uint16_t error_to_return = ERR_ASSERT;

    CRYPTO_VALIDATE(inSize >= DH_AES_IV_SIZE + CX_AES_BLOCK_SIZE + DH_HMAC_SIZE, ERR_INVALID_DATA);

    cx_hmac_sha256_t hmac;
    CRYPTO_CX_CHECK(cx_hmac_sha256_init_no_throw(&hmac, aesKey->km, SIZEOF(aesKey->km)));
    CRYPTO_CX_CHECK(cx_hmac_update((cx_hmac_t *) &hmac, buffer, inSize - DH_HMAC_SIZE));
    uint8_t hmacBuf[DH_HMAC_SIZE];
    size_t outLen = SIZEOF(hmacBuf);
    CRYPTO_CX_CHECK(cx_hmac_final((cx_hmac_t *) &hmac, hmacBuf, &outLen));
    CRYPTO_ASSERT(outLen == DH_HMAC_SIZE);
    CRYPTO_VALIDATE(!memcmp(hmacBuf, buffer + inSize - DH_HMAC_SIZE, DH_HMAC_SIZE),
                    ERR_INVALID_HMAC);
    error_to_return = SUCCESS;
end:
    explicit_bzero(hmacBuf, SIZEOF(hmacBuf));
    return error_to_return;
}

__noinline_due_to_stack__ WARN_UNUSED_RESULT uint16_t dh_decode(bip44_path_t *pathSpec,
                                                                public_key_t *publicKey,
                                                                uint8_t *buffer,
                                                                uint16_t *size) {
    // Crypto assets to be cleared
    dh_aes_key_t aesKey;
    explicit_bzero(&aesKey, SIZEOF(aesKey));

    // Variable for CRYPTO_ error handling macros
    uint16_t error_to_return = ERR_ASSERT;

    CRYPTO_VALIDATE(*size >= DH_AES_IV_SIZE + CX_AES_BLOCK_SIZE + DH_HMAC_SIZE, ERR_INVALID_DATA);
    CRYPTO_VALIDATE(*size % CX_AES_BLOCK_SIZE == 0, ERR_INVALID_DATA);

    // we do not decode IV, this also creates a buffer so we can decode inplace
    uint16_t read = DH_AES_IV_SIZE;
    uint16_t written = 0;
    CRYPTO_FORWARD_ERROR(dh_init_aes_key(&aesKey, pathSpec, publicKey));

    // validate HMAC
    CRYPTO_FORWARD_ERROR(validateHmac(&aesKey, buffer, *size));
    TRACE("HMAC validation succesfull.");

    // initiate DH decryptions
    uint8_t IV[CX_AES_BLOCK_SIZE];
    memcpy(IV, buffer, SIZEOF(IV));

    for (; read < *size - DH_HMAC_SIZE; read += CX_AES_BLOCK_SIZE) {
        // 1. Decode next block
        CRYPTO_ASSERT(read - written == CX_AES_BLOCK_SIZE);
        CRYPTO_CX_CHECK(cx_aes_dec_block(&aesKey.aesKey, buffer + read, buffer + written));
        // 2. XOR with IV
        for (uint16_t i = 0; i < CX_AES_BLOCK_SIZE; i++) {
            buffer[written + i] ^= IV[i];
        }
        // 3. Cyphertext is the new IV ... we do not care that we copy part of HMAC in last
        // iteration here
        memcpy(IV, buffer + read, CX_AES_BLOCK_SIZE);
        written += CX_AES_BLOCK_SIZE;
    }

    TRACE("Finishing decription, written:%d, lastCharacter:%d", written, buffer[written - 1]);
    // Calculate resulting length based on the last decoded value
    CRYPTO_VALIDATE(written != 0 && written >= buffer[written - 1], ERR_INVALID_DATA);

    *size = written - buffer[written - 1];
    error_to_return = SUCCESS;
end:
    explicit_bzero(&aesKey, SIZEOF(aesKey));
    return error_to_return;
}
