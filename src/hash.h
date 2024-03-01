#ifndef H_FIO_APP_HASH
#define H_FIO_APP_HASH

#include "common.h"
#include "lcx_sha512.h"

// This file provides convenience functions for using firmware hashing api

// Note: We would like to make this static const but
// it does not play well with inline functions
enum {
    SHA_256_SIZE = 32,
    SHA_512_SIZE = 64,
};

enum {
    HASH_CONTEXT_INITIALIZED_MAGIC = 12345,
};

typedef struct {
    uint16_t initialized_magic;
    cx_sha256_t cx_ctx;
} sha_256_context_t;

static __attribute__((always_inline, unused)) cx_err_t sha_256_init(sha_256_context_t* ctx) {
    cx_err_t err = cx_sha256_init_no_throw(&ctx->cx_ctx);
    if (err == CX_OK) {
        ctx->initialized_magic = HASH_CONTEXT_INITIALIZED_MAGIC;
    }
    return err;
}

static __attribute__((always_inline, unused)) cx_err_t sha_256_append(sha_256_context_t* ctx,
                                                                      const uint8_t* inBuffer,
                                                                      size_t inSize) {
    if (ctx->initialized_magic != HASH_CONTEXT_INITIALIZED_MAGIC ||
        inSize >= BUFFER_SIZE_PARANOIA) {
        return CX_INVALID_PARAMETER;
    }
    TRACE_BUFFER(inBuffer, inSize);
    return cx_hash_no_throw(&ctx->cx_ctx.header,
                            0, /* Do not output the hash, yet */
                            inBuffer,
                            inSize,
                            NULL,
                            0);
}

static __attribute__((always_inline, unused)) cx_err_t sha_256_finalize(sha_256_context_t* ctx,
                                                                        uint8_t* outBuffer,
                                                                        size_t outSize) {
    if (ctx->initialized_magic != HASH_CONTEXT_INITIALIZED_MAGIC || outSize != SHA_256_SIZE) {
        return CX_INVALID_PARAMETER;
    }
    return cx_hash_no_throw(&ctx->cx_ctx.header,
                            CX_LAST, /* Output the hash */
                            NULL,
                            0,
                            outBuffer,
                            SHA_256_SIZE);
}

/* Convenience function to make all in one step */
static __attribute__((always_inline, unused)) cx_err_t sha_256_hash(const uint8_t* inBuffer,
                                                                    size_t inSize,
                                                                    uint8_t* outBuffer,
                                                                    size_t outSize) {
    sha_256_context_t ctx;
    cx_err_t err = sha_256_init(&ctx);
    if (err != CX_OK) {
        return err;
    }
    err = sha_256_append(&ctx, inBuffer, inSize);
    if (err != CX_OK) {
        return err;
    }
    return sha_256_finalize(&ctx, outBuffer, outSize);
}

typedef struct {
    uint16_t initialized_magic;
    cx_sha512_t cx_ctx;
} sha_512_context_t;

static __attribute__((always_inline, unused)) cx_err_t sha_512_init(sha_512_context_t* ctx) {
    cx_err_t err = cx_sha512_init_no_throw(&ctx->cx_ctx);
    if (err == CX_OK) {
        ctx->initialized_magic = HASH_CONTEXT_INITIALIZED_MAGIC;
    }
    return err;
}

static __attribute__((always_inline, unused)) cx_err_t sha_512_append(sha_512_context_t* ctx,
                                                                      const uint8_t* inBuffer,
                                                                      size_t inSize) {
    if (ctx->initialized_magic != HASH_CONTEXT_INITIALIZED_MAGIC ||
        inSize >= BUFFER_SIZE_PARANOIA) {
        return CX_INVALID_PARAMETER;
    }

    TRACE_BUFFER(inBuffer, inSize);
    return cx_hash_no_throw(&ctx->cx_ctx.header,
                            0, /* Do not output the hash, yet */
                            inBuffer,
                            inSize,
                            NULL,
                            0);
}

static __attribute__((always_inline, unused)) cx_err_t sha_512_finalize(sha_512_context_t* ctx,
                                                                        uint8_t* outBuffer,
                                                                        size_t outSize) {
    if (ctx->initialized_magic != HASH_CONTEXT_INITIALIZED_MAGIC || outSize != SHA_512_SIZE) {
        return CX_INVALID_PARAMETER;
    }
    return cx_hash_no_throw(&ctx->cx_ctx.header,
                            CX_LAST, /* Output the hash */
                            NULL,
                            0,
                            outBuffer,
                            SHA_512_SIZE);
}

/* Convenience function to make all in one step */
static __attribute__((always_inline, unused)) cx_err_t sha_512_hash(const uint8_t* inBuffer,
                                                                    size_t inSize,
                                                                    uint8_t* outBuffer,
                                                                    size_t outSize) {
    sha_512_context_t ctx;
    cx_err_t err = sha_512_init(&ctx);
    if (err != CX_OK) {
        return err;
    }
    err = sha_512_append(&ctx, inBuffer, inSize);
    if (err != CX_OK) {
        return err;
    }
    return sha_512_finalize(&ctx, outBuffer, outSize);
}

#endif  // H_FIO_APP_HASH
