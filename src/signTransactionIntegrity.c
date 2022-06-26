#include "signTransactionIntegrity.h"
#include "state.h"
#include "hash.h"

static const uint8_t allowedHashes[][SHA_256_SIZE] = {
#ifdef DEVEL
    // Testing transaction template for signTransactionCommandsBasic.js
    {0x8a, 0xe3, 0x7f, 0xe4, 0x95, 0x02, 0x7a, 0xc1, 0x09, 0xde, 0x2e,
     0xe3, 0xf7, 0x95, 0x39, 0x14, 0x0f, 0xd5, 0x6a, 0xa5, 0x6a, 0x50,
     0xd3, 0xe9, 0x96, 0x83, 0x0e, 0x03, 0x3e, 0xda, 0x36, 0x76},
    // Testing transaction template for signTransactionCommandsShowData.js
    {0xe6, 0x61, 0x26, 0xce, 0x75, 0x57, 0xf1, 0x30, 0xca, 0x99, 0xd7,
     0xa3, 0x05, 0x1c, 0x81, 0x36, 0x80, 0xfa, 0x41, 0x02, 0xd7, 0x91,
     0x5c, 0xbd, 0x68, 0xe6, 0xe3, 0x61, 0xef, 0x85, 0x71, 0x03},
    // Testing transaction template for signTransactionCommandsCountedSection.js
    {0x2c, 0x55, 0x0f, 0x1f, 0x21, 0x8d, 0x01, 0x3a, 0x02, 0x7d, 0x2b,
     0x98, 0xbe, 0xfd, 0x5b, 0x82, 0x31, 0xc5, 0x7d, 0xcf, 0xe3, 0x63,
     0x45, 0x6a, 0x6e, 0x9c, 0x9c, 0xcf, 0xb7, 0xa5, 0x3b, 0x30},
    // Testing transaction template for signTransactionCommandsStorage.js
    {0x3c, 0xc2, 0xa2, 0x0d, 0xfb, 0x3b, 0xde, 0xf4, 0xdd, 0x17, 0xf9,
     0x97, 0x1c, 0xc8, 0x42, 0x1a, 0xc3, 0x9f, 0x6a, 0x63, 0x9d, 0x0d,
     0x5d, 0x9f, 0xb4, 0x24, 0xcf, 0x6b, 0xe5, 0x7c, 0x38, 0x29},
    // Testing transaction template for signTransactionCommandsDH.js
    {0xa3, 0x70, 0x53, 0x1e, 0xf3, 0x3e, 0xbe, 0x29, 0x3c, 0xb7, 0xcd,
     0xd3, 0xe4, 0x2b, 0xe0, 0x19, 0xa0, 0xdf, 0xb1, 0x2c, 0x92, 0xa1,
     0x08, 0x6c, 0xd8, 0x0b, 0xd4, 0xc5, 0x37, 0xce, 0xd2, 0xea},
    // Testing transaction template for signTransactionCommandsDHCountedSections.js
    {0x32, 0x94, 0xcb, 0xbb, 0x52, 0x16, 0xfb, 0xe3, 0xff, 0xba, 0x8a,
     0x8f, 0xdd, 0x9d, 0xa6, 0x4b, 0x7d, 0x27, 0x8d, 0x88, 0x53, 0xd0,
     0xfe, 0x52, 0x96, 0x02, 0xed, 0x5d, 0x96, 0x86, 0x20, 0xf0},
#endif
    // trnsfiopubky
    {0xb2, 0xaa, 0xb0, 0x41, 0xd8, 0xc0, 0x0c, 0x45, 0x22, 0x4c, 0xca, 
     0x7f, 0x76, 0x60, 0x20, 0x7a, 0xcc, 0x16, 0x71, 0x71, 0x84, 0x17, 
     0x3c, 0xb1, 0x12, 0x83, 0xb7, 0xe0, 0xe6, 0xe2, 0xaa, 0x98},
     // newfundsreq memo
    {0x08, 0x34, 0x3d, 0xea, 0xdb, 0x22, 0xe2, 0xe1, 0x55, 0xd6, 0xf8, 
     0xbe, 0xe0, 0x32, 0x8e, 0x25, 0xda, 0x3c, 0xea, 0x6e, 0xb9, 0xe2, 
     0x14, 0x3f, 0x13, 0x55, 0xf3, 0x31, 0xe7, 0xf7, 0x02, 0x67},     
     // newfundsreq hash
    {0x60, 0x25, 0xc4, 0x38, 0xb7, 0x7f, 0x55, 0x4f, 0x7f, 0x59, 0x4b, 
     0x58, 0xa9, 0x35, 0x57, 0xf9, 0x20, 0x44, 0x36, 0xbb, 0xd2, 0x9a, 
     0x5c, 0xe6, 0x90, 0x6d, 0xd4, 0x31, 0x55, 0x6d, 0xda, 0xf1}
};

enum {
    TX_INTEGRITY_HASH_INITIALIZED_MAGIC = 12345,
};

__noinline_due_to_stack__ void integrityCheckInit(tx_integrity_t *integrity) {
    explicit_bzero(integrity, SIZEOF(*integrity));
    integrity->initialized_magic = TX_INTEGRITY_HASH_INITIALIZED_MAGIC;

    TRACE_BUFFER(&integrity->integrityHash, SIZEOF(integrity->integrityHash));
}

__noinline_due_to_stack__ void integrityCheckProcessInstruction(tx_integrity_t *integrity,
                                                                uint8_t p1,
                                                                uint8_t p2,
                                                                const uint8_t *constData,
                                                                uint8_t constDataLength) {
    ASSERT(integrity->initialized_magic == TX_INTEGRITY_HASH_INITIALIZED_MAGIC);
    sha_256_context_t ctx;
    sha_256_init(&ctx);
    sha_256_append(&ctx, integrity->integrityHash, SIZEOF(integrity->integrityHash));
    sha_256_append(&ctx, &p1, SIZEOF(p1));
    sha_256_append(&ctx, &p2, SIZEOF(p2));
    sha_256_append(&ctx, &constDataLength, SIZEOF(constDataLength));
    sha_256_append(&ctx, constData, constDataLength);
    sha_256_finalize(&ctx, integrity->integrityHash, SIZEOF(integrity->integrityHash));

    TRACE_BUFFER(&integrity->integrityHash, SIZEOF(integrity->integrityHash));
}

__noinline_due_to_stack__ bool _integrityCheckFinalize(tx_integrity_t *integrity,
                                                       const uint8_t (*allowedHashes)[SHA_256_SIZE],
                                                       uint16_t allowedHashesLength) {
    ASSERT(integrity->initialized_magic == TX_INTEGRITY_HASH_INITIALIZED_MAGIC);
    for (uint16_t i = 0; i < allowedHashesLength; i++) {
        STATIC_ASSERT(SIZEOF(allowedHashes[i]) == SIZEOF(integrity->integrityHash),
                      "Incompatible hashes.");
        if (memcmp(integrity->integrityHash, allowedHashes[i], SIZEOF(allowedHashes[i])) == 0) {
            TRACE("Integrity check passed");
            return true;
        }
    }

    TRACE("Integrity check failed");
    return false;
}

__noinline_due_to_stack__ bool integrityCheckFinalize(tx_integrity_t *integrity) {
    return _integrityCheckFinalize(integrity, allowedHashes, ARRAY_LEN(allowedHashes));
}
