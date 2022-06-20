#ifdef DEVEL

#include "signTransactionIntegrity.h"
#include "hash.h"
#include "hexUtils.h"

static const char* allowedHashesHex[] = {
    "3732fb4f90aff701bbadb8a95b95d1e0ed2a60cf445a1d849fa79340c8d340a9",
};
static uint8_t allowedHashes[ARRAY_LEN(allowedHashesHex)][SHA_256_SIZE];

static void run1() {
    integrityCheckInit();
    const uint8_t data1[] = {3, 4};
    integrityCheckProcessInstruction(1, 2, data1, SIZEOF(data1));
    const uint8_t data2[] = {};
    integrityCheckProcessInstruction(5, 6, data2, SIZEOF(data2));
    _integrityCheckFinalize(allowedHashes, ARRAY_LEN(allowedHashes));
}

// modified p1
static void run2() {
    integrityCheckInit();
    const uint8_t data1[] = {3, 4};
    integrityCheckProcessInstruction(2, 2, data1, SIZEOF(data1));
    const uint8_t data2[] = {};
    integrityCheckProcessInstruction(5, 6, data2, SIZEOF(data2));
    ASSERT(!_integrityCheckFinalize(allowedHashes, ARRAY_LEN(allowedHashes)));
}

// modified p2
static void run3() {
    integrityCheckInit();
    const uint8_t data1[] = {3, 4};
    integrityCheckProcessInstruction(1, 3, data1, SIZEOF(data1));
    const uint8_t data2[] = {};
    integrityCheckProcessInstruction(5, 6, data2, SIZEOF(data2));
    ASSERT(!_integrityCheckFinalize(allowedHashes, ARRAY_LEN(allowedHashes)));
}

// modified data
static void run4() {
    integrityCheckInit();
    const uint8_t data1[] = {
        3,
    };
    integrityCheckProcessInstruction(1, 2, data1, SIZEOF(data1));
    const uint8_t data2[] = {};
    integrityCheckProcessInstruction(5, 6, data2, SIZEOF(data2));
    ASSERT(!_integrityCheckFinalize(allowedHashes, ARRAY_LEN(allowedHashes)));
}

// swapped instructions
static void run5() {
    integrityCheckInit();
    const uint8_t data1[] = {3, 4};
    const uint8_t data2[] = {};
    integrityCheckProcessInstruction(5, 6, data2, SIZEOF(data2));
    integrityCheckProcessInstruction(1, 2, data1, SIZEOF(data1));
    ASSERT(!_integrityCheckFinalize(allowedHashes, ARRAY_LEN(allowedHashes)));
}

// Less instruction and second, correc use
static void run6() {
    integrityCheckInit();
    const uint8_t data1[] = {3, 4};
    integrityCheckProcessInstruction(1, 2, data1, SIZEOF(data1));
    ASSERT(!_integrityCheckFinalize(allowedHashes, ARRAY_LEN(allowedHashes)));
    run1();
}

void run_integrityCheck_test() {
    // decode hex
    for (size_t i = 0; i < ARRAY_LEN(allowedHashes); i++) {
        decode_hex(allowedHashesHex[i], allowedHashes[i], SIZEOF(allowedHashes[i]));
    }

    // run tests
    run1();
    run2();
    run3();
    run4();
    run5();
    run6();
}

#endif  // DEVEL