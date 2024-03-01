#ifndef H_FIO_DIFFIE_HELLMAN
#define H_FIO_DIFFIE_HELLMAN

#include "common.h"
#include "ox_aes.h"
#include "exceptions.h"
#include "bip44.h"
#include "keyDerivation.h"
#include "hash.h"

// This file provides functions for Diffie-Hellmann encoding and decoding

// Note: We would like to make this static const but
// it does not play well with inline functions
enum {
    DH_CONTEXT_INITIALIZED_MAGIC = 12345,
    DH_AES_KEY_INITIALIZED_MAGIC = 12346,
};

#define DH_AES_IV_SIZE     16
#define DH_KM_SIZE         32
#define DH_AES_SECRET_SIZE 32
#define DH_HMAC_SIZE       32

#define BASE64_IN_BLOCK_SIZE  3
#define BASE64_OUT_BLOCK_SIZE 4

// Context does not contain secrets. hmacCtx contains half of SHA-512 hash, but this is of no use
// without aesKey.
typedef struct {
    uint16_t initialized_magic;
    uint8_t IV[DH_AES_IV_SIZE];
    uint8_t cacheLength;
    uint8_t cache[CX_AES_BLOCK_SIZE];
    uint8_t base64EncodingCacheLen;
    uint8_t base64EncodingCache[BASE64_IN_BLOCK_SIZE + DH_HMAC_SIZE];
    cx_hmac_sha256_t hmacCtx;
} dh_context_t;

// Aes key is secret shared between us and the second party
typedef struct {
    cx_aes_key_t aesKey;
    uint8_t km[DH_KM_SIZE];
} dh_aes_key_t;

/**
 * @brief   Generates shared secret AES key. Use only in crypto functions to guarantee cleanup.
 *
 * @param[out] dhKey           Resulting AES key.
 *
 * @param[in]  pathSpec        Our derivation path.
 *
 * @param[in]  publicKey       Their public key.
 *
 * @return                     Error code:
 *                             - SUCCESS on success
 *                             - ERR_REJECTED_BY_POLICY
 *                             - ERR_ASSERT for other unexpected errors
 */
__noinline_due_to_stack__ WARN_UNUSED_RESULT uint16_t
dh_init_aes_key(dh_aes_key_t *dhKey, const bip44_path_t *pathSpec, const public_key_t *publicKey);

/**
 * @brief   Initiates DH+Base64 ecoding.
 *
 * @param[out]     ctx             DH encoding context.
 *
 * @param[in]      pathSpec        Our derivation path.
 *
 * @param[in]      publicKey       Their public key.
 *
 * @param[in]      iv              Initiatlization vector.
 *
 * @param[in]      ivSize          Size of initialization vector.
 *
 * @param[out]     outBuffer       Output buffer, initialization produces cyphertext.
 *
 * @param[in, out] outSize        Size of output buffer. returns the number of new bytes.
 *
 * @return                     Error code:
 *                             - SUCCESS on success
 *                             - ERR_REJECTED_BY_POLICY
 *                             - ERR_ASSERT for other unexpected errors
 */
__noinline_due_to_stack__ WARN_UNUSED_RESULT uint16_t dh_encode_init(dh_context_t *ctx,
                                                                     const bip44_path_t *pathSpec,
                                                                     const public_key_t *publicKey,
                                                                     const uint8_t *iv,
                                                                     uint16_t ivSize,
                                                                     uint8_t *outBuffer,
                                                                     uint16_t *outSize);

/**
 * @brief   Append to DH+Base64 ecoded data.
 *
 * @param[in, out] ctx             DH encoding context.
 *
 * @param[in]      pathSpec        Our derivation path.
 *
 * @param[in]      publicKey       Their public key.
 *
 * @param[in]      inBuffer        Input buffer.
 *
 * @param[in]      inSize          Input buffer size.
 *
 * @param[out]     outBuffer       Output buffer, initialization produces cyphertext.
 *
 * @param[in, out] outSize        Size of output buffer. returns the number of new bytes.
 *
 * @return                         Error code:
 *                                 - SUCCESS on success
 *                                 - ERR_REJECTED_BY_POLICY
 *                                 - ERR_ASSERT for other unexpected errors
 */
__noinline_due_to_stack__ WARN_UNUSED_RESULT uint16_t
dh_encode_append(dh_context_t *ctx,
                 const bip44_path_t *pathSpec,
                 const public_key_t *publicKey,
                 const uint8_t *inBuffer,
                 uint16_t inSize,
                 uint8_t *outBuffer,
                 uint16_t *outSize);

/**
 * @brief   Finish DH+Base64 encoding.
 *
 * @param[in]      ctx             DH encoding context.
 *
 * @param[in]      pathSpec        Our derivation path.
 *
 * @param[in]      publicKey       Their public key.
 *
 * @param[out]     outBuffer       Output buffer, initialization produces cyphertext.
 *
 * @param[in, out] outSize         Size of output buffer. returns the number of new bytes.
 *
 * @return                         Error code:
 *                                 - SUCCESS on success
 *                                 - ERR_REJECTED_BY_POLICY
 *                                 - ERR_ASSERT for other unexpected errors
 */
__noinline_due_to_stack__ WARN_UNUSED_RESULT uint16_t
dh_encode_finalize(dh_context_t *ctx,
                   const bip44_path_t *pathSpec,
                   const public_key_t *publicKey,
                   uint8_t *outBuffer,
                   uint16_t *outSize);

/**
 * @brief   Inplace DH decoding function. Input data is NOT base64 encrypted
 *
 * @param[in]      pathSpec        Our derivation path.
 *
 * @param[in]      publicKey       Their public key.
 *
 * @param[out]     buffer          Output buffer, initialization produces cyphertext.
 *
 * @param[in, out] size            Size of output buffer. returns the number of new bytes.
 *
 * @return                         Error code:
 *                                 - SUCCESS on success
 *                                 - ERR_REJECTED_BY_POLICY
 *                                 - ERR_INVALID_DATA
 *                                 - ERR_INVALID_HMAC
 *                                 - ERR_ASSERT for other unexpected errors
 */
__noinline_due_to_stack__ WARN_UNUSED_RESULT uint16_t dh_decode(bip44_path_t *pathSpec,
                                                                public_key_t *publicKey,
                                                                uint8_t *buffer,
                                                                uint16_t *size);

#ifdef DEVEL
__noinline_due_to_stack__ WARN_UNUSED_RESULT uint16_t dh_encode(bip44_path_t *pathSpec,
                                                                public_key_t *publicKey,
                                                                const uint8_t *iv,
                                                                uint16_t ivSize,
                                                                const uint8_t *inBuffer,
                                                                uint16_t inSize,
                                                                uint8_t *outBuffer,
                                                                uint16_t *outSize);

__noinline_due_to_stack__ void run_diffieHellman_test();
#endif  // DEVEL

#endif
