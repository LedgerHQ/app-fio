#ifndef H_FIO_APP_KEY_DERIVATION
#define H_FIO_APP_KEY_DERIVATION

#include "common.h"
#include "handlers.h"
#include "bip44.h"
#include "utils.h"
#include "hash.h"

#define CHAIN_CODE_SIZE (32)

typedef cx_ecfp_private_key_t private_key_t;
typedef cx_ecfp_public_key_t public_key_t;

typedef struct {
    uint8_t code[CHAIN_CODE_SIZE];
} chain_code_t;

/**
 * @brief   Gets the private key from the device. Call this only from other crypto code.
 *
 * @param[in]  pathSpec        Derivation path.
 *
 * @param[out] privateKey      Private key.
 *
 * @return                     Error code:
 *                             - SUCCESS on success
 *                             - ERR_REJECTED_BY_POLICY
 *                             - ERR_ASSERT for other unexpected errors
 */
__noinline_due_to_stack__ WARN_UNUSED_RESULT uint16_t derivePrivateKey(const bip44_path_t* pathSpec,
                                                                       private_key_t* privateKey);

/**
 * @brief   Gets the public key from the device.
 *
 * @param[in]  pathSpec        Derivation path.
 *
 * @param[out] publicKey       Public key.
 *
 * @return                     Error code:
 *                             - SUCCESS on success
 *                             - ERR_REJECTED_BY_POLICY
 *                             - ERR_ASSERT for other unexpected errors
 */
__noinline_due_to_stack__ WARN_UNUSED_RESULT uint16_t derivePublicKey(const bip44_path_t* pathSpec,
                                                                      public_key_t* publicKey);

/**
 * @brief   Signs transaction hash.
 *
 * @param[in]  witnessPath     Derivation path.
 *
 * @param[in]  hashBuf         Hash to sign.
 *
 * @param[out] signature       Signature. The buffer should be sufficient for der_to_sig conversion.
 *                             This is meant to save space expecting that G_io_apdu_buffer is used.
 *
 * @param[in]  signatureLen    Length of the signature buffer.
 *
 * @return                     Error code:
 *                             - SUCCESS on success
 *                             - ERR_REJECTED_BY_POLICY
 *                             - ERR_ASSERT for other unexpected errors
 */
__noinline_due_to_stack__ WARN_UNUSED_RESULT uint16_t signTransaction(bip44_path_t* witnessPath,
                                                                      uint8_t hashBuf[SHA_256_SIZE],
                                                                      uint8_t* signature,
                                                                      size_t signatureLen);

#ifdef DEVEL
__noinline_due_to_stack__ void run_key_derivation_test();
#endif  // DEVEL

#endif  // H_FIO_APP_KEY_DERIVATION
