#ifdef DEVEL

#include "diffieHellman.h"
#include "hexUtils.h"
#include "testUtils.h"
#include "utils.h"
#include "bip44.h"
#include "errors.h"
#include "state.h"

#define HD HARDENED_BIP32

// The testcases here were generated using:
// To create shared secret (this creates SharedCipher instance):
// https://github.com/fioprotocol/fiojs/blob/10848a02983a4b5b7f185c90bc96fb78e9ab0a6f/src/encryption-fio.ts#L20
// For encryption (this is method of SharedCypher):
// https://github.com/fioprotocol/fiojs/blob/10848a02983a4b5b7f185c90bc96fb78e9ab0a6f/src/encryption-fio.ts#L52
// It was not very convenient to use higher level funtions for this purpose as they depend on fio
// serialization

__noinline_due_to_stack__ static void pathSpec_init(bip44_path_t* pathSpec,
                                                    const uint32_t* pathArray,
                                                    uint32_t pathLength) {
    pathSpec->length = pathLength;
    memmove(pathSpec->path, pathArray, pathLength * 4);
}

__noinline_due_to_stack__ static void run_dh_encode_tests() {
    BEGIN_ASSERT_NOEXCEPT {
        TRACE_STACK_USAGE();
        // initializing derivation paths
        uint32_t path[] = {HD + 44, HD + 235, HD + 0, 0, 0};
        bip44_path_t pathSpec;
        pathSpec_init(&pathSpec, path, 5);
        bip44_PRINTF(&pathSpec);
        PRINTF("\n");

        public_key_t publicKey;
        const uint8_t publicKeyBuffer[65] = {
            0x04, 0x84, 0xe5, 0x2d, 0xfe, 0xa5, 0x7b, 0x8f, 0x17, 0x87, 0x48, 0x8a, 0x35,
            0x63, 0x74, 0xcd, 0x8e, 0x85, 0x15, 0xb8, 0xad, 0x8d, 0xb3, 0xdd, 0x4f, 0x90,
            0x88, 0xd8, 0xe4, 0x2e, 0xd2, 0xfb, 0x6d, 0x57, 0x1e, 0x88, 0x94, 0xcc, 0xcb,
            0xdb, 0xf1, 0x5e, 0x1b, 0xd8, 0x4f, 0x8b, 0x43, 0x62, 0xf5, 0x2d, 0x1b, 0x5b,
            0x71, 0x2b, 0x97, 0x75, 0xc0, 0xa5, 0x1c, 0xdd, 0x5e, 0xe9, 0xa9, 0xe8, 0xca,
        };
        size_t publicKeyLen = 65;
        cx_ecfp_init_public_key_no_throw(CX_CURVE_SECP256K1,
                                         publicKeyBuffer,
                                         publicKeyLen,
                                         &publicKey);

        const uint8_t IV[DH_AES_IV_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

#define TESTCASE(msgHex_, expectedEncMsg)                                \
    {                                                                    \
        const char* msgHex = msgHex_;                                    \
        uint8_t msg[50];                                                 \
        size_t msgLen = decode_hex(msgHex, msg, SIZEOF(msg));            \
        uint8_t encMsg[200];                                             \
        uint16_t encMsgLength = SIZEOF(encMsg);                          \
        uint16_t err = dh_encode(&pathSpec,                              \
                                 &publicKey,                             \
                                 IV,                                     \
                                 DH_AES_IV_SIZE,                         \
                                 msg,                                    \
                                 msgLen,                                 \
                                 encMsg,                                 \
                                 &encMsgLength);                         \
        ASSERT(err == SUCCESS);                                          \
        TRACE_BUFFER(encMsg, encMsgLength);                              \
        ASSERT(encMsgLength == strlen(expectedEncMsg));                  \
        EXPECT_EQ_BYTES(encMsg, expectedEncMsg, strlen(expectedEncMsg)); \
    }
        TESTCASE("0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef",
                 "AAECAwQFBgcICQoLDA0OD5UItJL5bwZ8xy74x8JKwgcjEMTh02vWc3lY8KOgBVdtYLZLjoxzLYk/"
                 "bNN0yrwLMIgrbuurp69ygm5UsR1IqHBZdK332VerofQo9YrKJaxa");

        TESTCASE("0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef00",
                 "AAECAwQFBgcICQoLDA0OD5UItJL5bwZ8xy74x8JKwgcjEMTh02vWc3lY8KOgBVdt+"
                 "TtaLr71hTLsLS3SHBH9tZDQWlmHQK+P2SYzQ+sdhafmlDwh0lRoLQvcTHRhnqIs");

        TESTCASE("0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0011",
                 "AAECAwQFBgcICQoLDA0OD5UItJL5bwZ8xy74x8JKwgcjEMTh02vWc3lY8KOgBVdtK4jF9Qm7cnajL5RZX"
                 "hls84KwYlmS3RlCEKDlRUEHQagBOhItLt2SM8qj/Ut1+ZRs");

        TESTCASE(
            "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef00112233445566778899aa"
            "bbccddee",
            "AAECAwQFBgcICQoLDA0OD5UItJL5bwZ8xy74x8JKwgcjEMTh02vWc3lY8KOgBVdt+ZmX+"
            "ip0JmWwHDXH1srrwvvRvUR5y4GetFISOg7GNW9AIi9/yM68OluB9kTy91Yp");

        TESTCASE(
            "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef00112233445566778899aa"
            "bbccddeeff",
            "AAECAwQFBgcICQoLDA0OD5UItJL5bwZ8xy74x8JKwgcjEMTh02vWc3lY8KOgBVdtYKY7MOUtuZP9tT9nugPNCr"
            "7YlPVJKaxq3f1wdpcFl6Q6NsUlrR/ENJxpviFxirB7xjkXJmOSfLB1+nd3l+DBxA==");

        TESTCASE("0123456789abcdef0123456789abcdef0123456789abcdef",
                 "AAECAwQFBgcICQoLDA0OD5UItJL5bwZ8xy74x8JKwgep9INSMYlu/SPdSUMhBnjaVsV/"
                 "Jx4eXIRvvwVVn9G3OUBpKtEm9+G1b3GYumJrYoc=");

#undef TESTCASE
    }
    END_ASSERT_NOEXCEPT;
}

__noinline_due_to_stack__ static void run_dh_encode_init_append_finalize_tests() {
    BEGIN_ASSERT_NOEXCEPT {
        TRACE_STACK_USAGE();

        // initializing derivation paths
        uint32_t path[] = {HD + 44, HD + 235, HD + 0, 0, 2000};
        bip44_path_t pathSpec;
        pathSpec_init(&pathSpec, path, 5);
        bip44_PRINTF(&pathSpec);
        PRINTF("\n");

        public_key_t publicKey;
        {
            const char* publicKeyHex =
                "0484e52dfea57b8f1787488a356374cd8e8515b8ad8db3dd4f9088d8e42ed2fb6d571e8894cccbdbf1"
                "5e1b"
                "d84f8b4362f52d1b5b712b9775c0a51cdd5ee9a9e8ca";
            uint8_t publicKeyBuffer[65];
            size_t publicKeyLen =
                decode_hex(publicKeyHex, publicKeyBuffer, SIZEOF(publicKeyBuffer));
            ASSERT(publicKeyLen == 65);
            cx_ecfp_init_public_key_no_throw(CX_CURVE_SECP256K1,
                                             publicKeyBuffer,
                                             publicKeyLen,
                                             &publicKey);
        }

        const uint8_t IV[DH_AES_IV_SIZE] =
            {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};

        uint8_t inBuffer[50];
        uint8_t outBuffer[160];
        const char* inBufferHex =
            "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef00112233445566778899aa"
            "bbccddeeff";
        size_t inBufferLength = decode_hex(inBufferHex, inBuffer, SIZEOF(inBuffer));
        const char* expected =
            "ZGRkZGRkZGRkZGRkZGRkZECnJe7JYjYZ/UIsDOe/"
            "llUGwVFl+lJ3Qpxm5u0fLG9kxuEGaN18XnBMEu6iJXmhERjaQhHhN4L/"
            "gZPs9AD9BNvPMXpd9H9EnR27den0hCjQqECg6QE5dZrTnSiZDLN/Yg==";

        uint16_t outBufferLength = SIZEOF(outBuffer);
        uint16_t err = dh_encode(&pathSpec,
                                 &publicKey,
                                 IV,
                                 DH_AES_IV_SIZE,
                                 inBuffer,
                                 inBufferLength,
                                 outBuffer,
                                 &outBufferLength);
        ASSERT(err == SUCCESS);
        TRACE_BUFFER(outBuffer, outBufferLength);
        ASSERT(outBufferLength == strlen(expected));
        EXPECT_EQ_BYTES(expected, outBuffer, outBufferLength);

        size_t read = 0;
        size_t written = 0;
        {
            TRACE_STACK_USAGE();
            // due to memory limitations we reuse static tx data
            dh_context_t* ctx = &instructionState.signTransactionContext.dhContext;
            outBufferLength = SIZEOF(outBuffer);
            err = dh_encode_init(ctx,
                                 &pathSpec,
                                 &publicKey,
                                 IV,
                                 SIZEOF(IV),
                                 outBuffer,
                                 &outBufferLength);
            ASSERT(err == SUCCESS);
            ASSERT(outBufferLength == 20);
            EXPECT_EQ_BYTES(expected + written, outBuffer, 20);
            written += 20;  // Cache 0b, 1b

            {
                outBufferLength = SIZEOF(outBuffer);
                err = dh_encode_append(ctx,
                                       &pathSpec,
                                       &publicKey,
                                       inBuffer + read,
                                       1,
                                       outBuffer,
                                       &outBufferLength);
                ASSERT(err == SUCCESS);
                ASSERT(outBufferLength == 0);
                read += 1;  // Cache 1b, 1b
            }
            {
                outBufferLength = SIZEOF(outBuffer);
                err = dh_encode_append(ctx,
                                       &pathSpec,
                                       &publicKey,
                                       inBuffer + read,
                                       14,
                                       outBuffer,
                                       &outBufferLength);
                ASSERT(err == SUCCESS);
                ASSERT(outBufferLength == 0);
                read += 14;  // Cache 15b, 1b
            }

            outBufferLength = SIZEOF(outBuffer);
            err = dh_encode_append(ctx,
                                   &pathSpec,
                                   &publicKey,
                                   inBuffer + read,
                                   18,
                                   outBuffer,
                                   &outBufferLength);
            ASSERT(err == SUCCESS);
            ASSERT(outBufferLength == 44);
            EXPECT_EQ_BYTES(expected + written, outBuffer, 44);
            read += 18, written += 44;  // Cache 1b, 0b

            outBufferLength = SIZEOF(outBuffer);
            err = dh_encode_append(ctx,
                                   &pathSpec,
                                   &publicKey,
                                   inBuffer + read,
                                   1,
                                   outBuffer,
                                   &outBufferLength);
            ASSERT(err == SUCCESS);
            ASSERT(outBufferLength == 0);
            read += 1;  // Cache 2b, 0b

            outBufferLength = SIZEOF(outBuffer);
            err = dh_encode_append(ctx,
                                   &pathSpec,
                                   &publicKey,
                                   inBuffer + read,
                                   14,
                                   outBuffer,
                                   &outBufferLength);
            ASSERT(err == SUCCESS);
            ASSERT(outBufferLength == 20);
            EXPECT_EQ_BYTES(expected + written, outBuffer, 20);
            read += 14, written += 20;  // Cache 0b, 1b

            outBufferLength = SIZEOF(outBuffer);
            err = dh_encode_finalize(ctx, &pathSpec, &publicKey, outBuffer, &outBufferLength);
            ASSERT(err == SUCCESS);
            ASSERT(outBufferLength == 68);
            EXPECT_EQ_BYTES(expected + written, outBuffer, 68);
            written += 68;

            ASSERT(read == inBufferLength);
        }
    }
    END_ASSERT_NOEXCEPT;
}

__noinline_due_to_stack__ static void run_dh_decode_tests() {
    BEGIN_ASSERT_NOEXCEPT {
        TRACE_STACK_USAGE();
        // initializing derivation paths
        uint32_t path[] = {HD + 44, HD + 235, HD + 0, 0, 2000};
        bip44_path_t pathSpec;
        pathSpec_init(&pathSpec, path, 5);
        bip44_PRINTF(&pathSpec);
        PRINTF("\n");

        public_key_t publicKey;
        const char* publicKeyHex =
            "04a9a222bc3b1a5a58ada17d10069b3961ebd0f917d4b2106031a061915ca9cc24a06941e0a4c0d5e2668"
            "50ff980ad349ab8b027c93bf4aead1984168ad43e30ab";
        uint8_t publicKeyBuffer[65];
        size_t publicKeyLen = decode_hex(publicKeyHex, publicKeyBuffer, SIZEOF(publicKeyBuffer));
        ASSERT(publicKeyLen == 65);
        cx_ecfp_init_public_key_no_throw(CX_CURVE_SECP256K1,
                                         publicKeyBuffer,
                                         publicKeyLen,
                                         &publicKey);

        TRACE_STACK_USAGE();

#define TESTCASE(msgHex_, expectedDecMsgHex_)                                      \
    {                                                                              \
        const char* msgHex = msgHex_;                                              \
        uint8_t msg[120];                                                          \
        uint16_t msgLen = decode_hex(msgHex, msg, SIZEOF(msg));                    \
        const char* expectedDecMsgHex = expectedDecMsgHex_;                        \
        uint8_t expectedDecMsg[100];                                               \
        size_t expectedMsgLen =                                                    \
            decode_hex(expectedDecMsgHex, expectedDecMsg, SIZEOF(expectedDecMsg)); \
        uint16_t err = dh_decode(&pathSpec, &publicKey, msg, &msgLen);             \
        ASSERT(err == SUCCESS);                                                    \
        TRACE("Decoded mesage %d, %d", msgLen, expectedMsgLen);                    \
        ASSERT(msgLen == expectedMsgLen);                                          \
        EXPECT_EQ_BYTES(msg, expectedDecMsg, msgLen);                              \
    }
        TESTCASE(
            "000102030405060708090a0b0c0d0e0f9508b492f96f067cc72ef8c7c24ac2072310c4e1d36bd6737958f0"
            "a3a005576d60b64b8e8c732d893f6cd374cabc0b30882b6eebaba7af72826e54b11d48a8705974adf7d957"
            "aba1f428f58aca25ac5a",
            "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef");

        TESTCASE(
            "000102030405060708090a0b0c0d0e0f9508b492f96f067cc72ef8c7c24ac2072310c4e1d36bd6737958f0"
            "a3a005576df93b5a2ebef58532ec2d2dd21c11fdb590d05a598740af8fd9263343eb1d85a7e6943c21d254"
            "682d0bdc4c74619ea22c",
            "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef00");

        TESTCASE(
            "000102030405060708090a0b0c0d0e0f9508b492f96f067cc72ef8c7c24ac2072310c4e1d36bd6737958f0"
            "a3a005576d2b88c5f509bb7276a32f94595e196cf382b0625992dd194210a0e545410741a8013a122d2edd"
            "9233caa3fd4b75f9946c",
            "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef0011");

        TESTCASE(
            "000102030405060708090a0b0c0d0e0f9508b492f96f067cc72ef8c7c24ac2072310c4e1d36bd6737958f0"
            "a3a005576df99997fa2a742665b01c35c7d6caebc2fbd1bd4479cb819eb452123a0ec6356f40222f7fc8ce"
            "bc3a5b81f644f2f75629",
            "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef00112233445566778899aa"
            "bbccddee");

        TESTCASE(
            "000102030405060708090a0b0c0d0e0f9508b492f96f067cc72ef8c7c24ac2072310c4e1d36bd6737958f0"
            "a3a005576d60a63b30e52db993fdb53f67ba03cd0abed894f54929ac6addfd7076970597a43a36c525ad1f"
            "c4349c69be21718ab07bc639172663927cb075fa777797e0c1c4",
            "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef00112233445566778899aa"
            "bbccddeeff");

        TESTCASE(
            "000102030405060708090a0b0c0d0e0f9508b492f96f067cc72ef8c7c24ac207a9f4835231896efd23dd49"
            "43210678da56c57f271e1e5c846fbf05559fd1b73940692ad126f7e1b56f7198ba626b6287",
            "0123456789abcdef0123456789abcdef0123456789abcdef")

        TRACE_STACK_USAGE();

#undef TESTCASE
    }
    END_ASSERT_NOEXCEPT;
}

__noinline_due_to_stack__ static void run_dh_decode_failed_hmac_tests() {
    TRACE_STACK_USAGE();
    // initializing derivation paths
    uint32_t path[] = {HD + 44, HD + 235, HD + 0, 0, 2000};
    bip44_path_t pathSpec;
    pathSpec_init(&pathSpec, path, 5);
    bip44_PRINTF(&pathSpec);
    PRINTF("\n");

    public_key_t publicKey;
    const char* publicKeyHex =
        "04a9a222bc3b1a5a58ada17d10069b3961ebd0f917d4b2106031a061915ca9cc24a06941e0a4c0d5e2668"
        "50ff980ad349ab8b027c93bf4aead1984168ad43e30ab";
    uint8_t publicKeyBuffer[65];
    size_t publicKeyLen = decode_hex(publicKeyHex, publicKeyBuffer, SIZEOF(publicKeyBuffer));
    ASSERT(publicKeyLen == 65);
    cx_ecfp_init_public_key_no_throw(CX_CURVE_SECP256K1, publicKeyBuffer, publicKeyLen, &publicKey);

    TRACE_STACK_USAGE();

    //"000102030405060708090a0b0c0d0e0f9508b492f96f067cc72ef8c7c24ac2072310c4e1d36bd6737958f0a3a005576d60a63b30e52db993fdb53f67ba03cd0abed894f54929ac6addfd7076970597a43a36c525ad1fc4349c69be21718ab07bc639172663927cb075fa777797e0c1c4";we
    // change first byte
    const char* msgHex =
        "100102030405060708090a0b0c0d0e0f9508b492f96f067cc72ef8c7c24ac2072310c4e1d36bd6737958f0a3a0"
        "05576d60a63b30e52db993fdb53f67ba03cd0abed894f54929ac6addfd7076970597a43a36c525ad1fc4349c69"
        "be21718ab07bc639172663927cb075fa777797e0c1c4";
    uint8_t msg[120];
    uint16_t msgLen = decode_hex(msgHex, msg, SIZEOF(msg));

    ASSERT(dh_decode(&pathSpec, &publicKey, msg, &msgLen) == ERR_INVALID_HMAC);
}

__noinline_due_to_stack__ void run_diffieHellman_test() {
    PRINTF("Running DH tests\n");
    PRINTF("If they fail, make sure you seeded your device with\n");
    PRINTF("12-word mnemonic: 11*abandon about\n");
    TRACE_STACK_USAGE();
    run_dh_encode_tests();
    TRACE_STACK_USAGE();
    run_dh_encode_init_append_finalize_tests();
    TRACE_STACK_USAGE();
    run_dh_decode_tests();
    TRACE_STACK_USAGE();
    run_dh_decode_failed_hmac_tests();
    TRACE_STACK_USAGE();
}

#endif  // DEVEL
