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
    uint16_t initialized_magic;
    cx_aes_key_t aesKey;
    uint8_t km[DH_KM_SIZE];
} dh_aes_key_t;

// You may need to call multiple times if encryption spans multiple APDU's
// You may want to do something like
// APDU1 - dh_init_aes_key, dh_encode_init, dh_encode_append
// APDU2 - dh_init_aes_key, dh_encode_append
// APDU3 - dh_init_aes_key, dh_encode_append, dh_encode_finalize
// Do not forget to guarantee that dh_aes_key_t is zeroes at all times

__noinline_due_to_stack__ void dh_init_aes_key(dh_aes_key_t* dhKey,
                                               const bip44_path_t* pathSpec,
                                               const public_key_t* publicKey);

// Output data are base64 encrypted
__noinline_due_to_stack__ size_t dh_encode_init(dh_context_t* ctx,
                                                const dh_aes_key_t* aes_key,
                                                const uint8_t* iv,
                                                size_t ivSize,
                                                uint8_t* outBuffer,
                                                size_t outSize);

// Output data are base64 encrypted
__noinline_due_to_stack__ size_t dh_encode_append(dh_context_t* ctx,
                                                  const dh_aes_key_t* aes_key,
                                                  const uint8_t* inBuffer,
                                                  size_t inSize,
                                                  uint8_t* outBuffer,
                                                  size_t outSize);

// Output data are base64 encrypted
__noinline_due_to_stack__ size_t dh_encode_finalize(dh_context_t* ctx,
                                                    const dh_aes_key_t* aes_key,
                                                    uint8_t* outBuffer,
                                                    size_t outSize);

// Convenience function to make all in one step
// Output data are base64 encrypted
__noinline_due_to_stack__ size_t dh_encode(bip44_path_t* pathSpec,
                                           public_key_t* publicKey,
                                           const uint8_t* iv,
                                           size_t ivSize,
                                           const uint8_t* inBuffer,
                                           size_t inSize,
                                           uint8_t* outBuffer,
                                           size_t outSize);

// Inplace decoding function.
// Input data is NOT base64 encrypted
__noinline_due_to_stack__ size_t dh_decode(bip44_path_t* pathSpec,
                                           public_key_t* publicKey,
                                           uint8_t* buffer,
                                           size_t inSize);

#ifdef DEVEL
__noinline_due_to_stack__ void run_diffieHellman_test();
#endif  // DEVEL

#endif
