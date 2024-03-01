#include "common.h"
#include "handlers.h"
#include "eos_utils.h"
#include "getSerial.h"
#include "state.h"
#include "fio.h"
#include "hash.h"
#include "lcx_rng.h"
#include "securityPolicy.h"
#include "signTransactionCountedSection.h"
#include "signTransactionIntegrity.h"
#include "signTransactionParse.h"
#include "uiHelpers.h"
#include "uiScreens.h"
#include "textUtils.h"

static ins_sign_transaction_context_t* ctx = &(instructionState.signTransactionContext);

// ============================== MISC ==============================

typedef enum {
    VALUE_STORAGE_CHECK_NO = 0x00,
    VALUE_STORAGE_CHECK_R1 = 0x10,
    VALUE_STORAGE_CHECK_R2 = 0x20,
    VALUE_STORAGE_CHECK_R3 = 0x30,
    VALUE_STORAGE_CHECK_R1_DECODE_NAME = 0x40,
} tx_storage_check_t;

enum {
    TX_STORAGE_INITIALIZED_MAGIC = 12345,
};

enum {
    TX_INIT_WAS_CALLED_INITIALIZED_MAGIC = 12346,
};

// Uses ctx->dataToAppendToTx, ctx->dataToAppendToTxLen to extend hash
// If ctx->dhIsActive then, we extend hash with encrypted data and prepare resulting encrypted
// blocks to G_io_apdu_buffer, ctx->responseLength Variables (&ctx->witnessPath, &ctx->otherPubkey,
// &ctx->dhContext) are needed for encryption
static void processShaAndPosibleDHAndPrepareResponse() {
    if (ctx->dhIsActive) {
        uint16_t bufferLen = SIZEOF(G_io_apdu_buffer);
        {
            uint16_t err = dh_encode_append(&ctx->dhContext,
                                            &ctx->witnessPath,
                                            &ctx->otherPubkey,
                                            ctx->dataToAppendToTx,
                                            ctx->dataToAppendToTxLen,
                                            G_io_apdu_buffer,
                                            &bufferLen);
            if (err != SUCCESS) {
                THROW(err);
            }
        }
        ctx->responseLength = bufferLen;
        {
            cx_err_t err = sha_256_append(&ctx->hashContext, G_io_apdu_buffer, ctx->responseLength);
            ASSERT(err == CX_OK);
        }
        VALIDATE(ctx->countedSectionDifference + ctx->responseLength >= ctx->dataToAppendToTxLen,
                 ERR_INVALID_STATE);
        ctx->countedSectionDifference =
            ctx->countedSectionDifference + ctx->responseLength - ctx->dataToAppendToTxLen;
        TRACE("CS diff %d from:%d, %d",
              (int) ctx->countedSectionDifference,
              (int) ctx->responseLength,
              (int) ctx->dataToAppendToTxLen);
    } else {
        cx_err_t err =
            sha_256_append(&ctx->hashContext, ctx->dataToAppendToTx, ctx->dataToAppendToTxLen);
        ASSERT(err == CX_OK);
        ctx->responseLength = 0;
    }
}

// Takes &ctx->witnessPath and modifies ctx->value to be null terminated scting to display the
// pubkey
static void prepareOurPubkeyForDisplay() {
    public_key_t witnessPathPubkey;
    explicit_bzero(&witnessPathPubkey, SIZEOF(witnessPathPubkey));
    uint16_t err = derivePublicKey(&ctx->witnessPath, &witnessPathPubkey);
    ASSERT(err == SUCCESS);
    TRACE_BUFFER(witnessPathPubkey.W, SIZEOF(witnessPathPubkey.W));

    uint32_t outlen = public_key_to_wif(witnessPathPubkey.W,
                                        SIZEOF(witnessPathPubkey.W),
                                        ctx->value,
                                        SIZEOF(ctx->value));
    ASSERT(outlen != 0);
    ASSERT(outlen < SIZEOF(ctx->value));
    ctx->value[outlen] = 0;
}

// Simple reusable UI step with one or no screens
enum {
    HANDLE_SIMPLE_STEP_DISPLAY_DETAILS = 100,
    HANDLE_SIMPLE_STEP_RESPOND,
    HANDLE_SIMPLE_STEP_INVALID,
};

static void signTx_ui_runStep_simple() {
    TRACE("UI step %d", ctx->ui_step);
    TRACE_STACK_USAGE();
    ui_callback_fn_t* this_fn = signTx_ui_runStep_simple;

    UI_STEP_BEGIN(ctx->ui_step, this_fn);

    UI_STEP(HANDLE_SIMPLE_STEP_DISPLAY_DETAILS) {
        ui_displayPaginatedText(ctx->key, ctx->value, this_fn);
    }

    UI_STEP(HANDLE_SIMPLE_STEP_RESPOND) {
        TRACE();
        io_send_buf(SUCCESS, G_io_apdu_buffer, ctx->responseLength);
        ui_displayBusy();  // needs to happen after I/O
    }

    UI_STEP_END(HANDLE_SIMPLE_STEP_INVALID);
}

// ============================== INIT ==============================

__noinline_due_to_stack__ void signTx_handleInitAPDU(uint8_t p2,
                                                     MARK_UNUSED_NO_DEVEL uint8_t* constDataBuffer,
                                                     size_t constSize,
                                                     uint8_t* varDataBuffer,
                                                     size_t varSize) {
    // Sanity checks and trace buffers
    TRACE_STACK_USAGE();
    {
        VALIDATE(p2 == P2_UNUSED, ERR_INVALID_REQUEST_PARAMETERS);
        TRACE_BUFFER(constDataBuffer, constSize);
        TRACE_BUFFER(varDataBuffer, varSize);
    }

    // Data format
    VALIDATE(constSize == 0, ERR_INVALID_DATA);
    struct {
        uint8_t chainId[CHAIN_ID_LENGTH];
        uint8_t derivationPath[1 + sizeof(uint32_t) *
                                       BIP44_MAX_PATH_ELEMENTS];  // 1 stands for number of
                                                                  // derivation math elements
    }* varData = (void*) varDataBuffer;
    VALIDATE(varSize >= SIZEOF(varData->chainId), ERR_INVALID_DATA);

    // Parsing: network, ctx->witnessPath, ctx->dataToAppendToTx,
    network_type_t network = NETWORK_UNKNOWN;
    {
        network = getNetworkByChainId(varData->chainId, SIZEOF(varData->chainId));
        TRACE("Chain: %d", (int) network);
        VALIDATE(network == NETWORK_MAINNET || network == NETWORK_TESTNET, ERR_INVALID_DATA);

        const size_t parsedSize = bip44_parseFromWire(&ctx->witnessPath,
                                                      varData->derivationPath,
                                                      varSize - SIZEOF(varData->chainId));
        BIP44_PRINTF(&ctx->witnessPath);
        PRINTF("\n");
        VALIDATE(parsedSize == varSize - SIZEOF(varData->chainId), ERR_INVALID_DATA);

        STATIC_ASSERT(SIZEOF(ctx->dataToAppendToTx) >= SIZEOF(varData->chainId),
                      "Buffer too small");
        memcpy(ctx->dataToAppendToTx, varData->chainId, SIZEOF(varData->chainId));
        ctx->dataToAppendToTxLen = SIZEOF(varData->chainId);
    }

    // Prepare display variables ctx->key, ctx->value
    {
        TRACE_STACK_USAGE();
        snprintf(ctx->key, MAX_DISPLAY_KEY_LENGTH, "Chain");
        switch (network) {
#define CASE(NETWORK, CHAIN_STRING)                                   \
    case NETWORK: {                                                   \
        snprintf(ctx->value, MAX_DISPLAY_VALUE_LENGTH, CHAIN_STRING); \
        break;                                                        \
    }
            CASE(NETWORK_MAINNET, "Mainnet");
            CASE(NETWORK_TESTNET, "Testnet");
            default:
                THROW(ERR_NOT_IMPLEMENTED);
#undef CASE
        }
    }
    // Reading data finished, from now on we use G_io_apdu_buffer for output

    // Append data to hash and prepare response (none)
    {
        TRACE_STACK_USAGE();
        VALIDATE(!ctx->dhIsActive, ERR_INVALID_STATE);
        VALIDATE(countedSectionProcess(&ctx->countedSections, ctx->dataToAppendToTxLen),
                 ERR_INVALID_DATA);
        ASSERT(sha_256_append(&ctx->hashContext, ctx->dataToAppendToTx, ctx->dataToAppendToTxLen) ==
               CX_OK);

        ctx->responseLength = 0;
    }

    // Security policy
    security_policy_t policy = POLICY_DENY;
    {
        policy = policyForSignTxInit(&ctx->witnessPath);
        TRACE("Policy: %d", (int) policy);
        ENSURE_NOT_DENIED(policy);
        // select UI step
        if (policy == POLICY_SHOW_BEFORE_RESPONSE) {
            ctx->ui_step = HANDLE_SIMPLE_STEP_DISPLAY_DETAILS;
        } else {
            THROW(ERR_NOT_IMPLEMENTED);
        }
    }

    // Run ui step
    signTx_ui_runStep_simple();
}

// ======================= APPEND CONST DATA ===========================

__noinline_due_to_stack__ void signTx_handleAppendConstDataAPDU(
    uint8_t p2,
    uint8_t* constDataBuffer,
    size_t constSize,
    MARK_UNUSED_NO_DEVEL uint8_t* varDataBuffer,
    size_t varSize) {
    // Sanity checks and trace buffers
    TRACE_STACK_USAGE();
    {
        VALIDATE(p2 == P2_UNUSED, ERR_INVALID_REQUEST_PARAMETERS);
        TRACE_BUFFER(constDataBuffer, constSize);
        TRACE_BUFFER(varDataBuffer, varSize);
    }

    // Data format
    struct {
        uint8_t data[MAX_TX_APPEND_IN_SINGLE_APDU];
    }* constData = (void*) constDataBuffer;
    VALIDATE(constSize < MAX_TX_APPEND_IN_SINGLE_APDU, ERR_INVALID_DATA);
    VALIDATE(varSize == 0, ERR_INVALID_DATA);

    // Parsing: ctx->dataToAppendToTx, ctx->dataToAppendToTxLen
    // Preparing display variables ctx->key, ctx->value
    {
        memcpy(ctx->dataToAppendToTx, constData, constSize);
        ctx->dataToAppendToTxLen = constSize;
        ctx->key[0] = 0;
        ctx->value[0] = 0;
    }
    // Reading data finished, from now on we use G_io_apdu_buffer for output

    // Append data to hash (with possible DH encryption) and prepare response
    {
        VALIDATE(countedSectionProcess(&ctx->countedSections, ctx->dataToAppendToTxLen),
                 ERR_INVALID_DATA);
        processShaAndPosibleDHAndPrepareResponse();
    }

    // Run ui step
    ctx->ui_step = HANDLE_SIMPLE_STEP_RESPOND;
    signTx_ui_runStep_simple();
}

// ======================= SHOW MESSAGE ===========================

__noinline_due_to_stack__ void signTx_handleShowMessageAPDU(
    uint8_t p2,
    uint8_t* constDataBuffer,
    size_t constSize,
    MARK_UNUSED_NO_DEVEL uint8_t* varDataBuffer,
    size_t varSize) {
    // Sanity checks and trace buffers
    TRACE_STACK_USAGE();
    {
        VALIDATE(p2 == P2_UNUSED, ERR_INVALID_REQUEST_PARAMETERS);
        TRACE_BUFFER(constDataBuffer, constSize);
        TRACE_BUFFER(varDataBuffer, varSize);
    }

    // Data format
    struct {
        uint8_t displayKeyLen;
        uint8_t displayKey[MAX_DISPLAY_KEY_LENGTH];
    }* constData = (void*) constDataBuffer;
    VALIDATE(constSize >= 1, ERR_INVALID_DATA);
    VALIDATE(constData->displayKeyLen < MAX_DISPLAY_KEY_LENGTH - 1, ERR_INVALID_DATA);
    VALIDATE(constSize >= 2 + constData->displayKeyLen, ERR_INVALID_DATA);
    struct {
        uint8_t displayValueLen;
        uint8_t displayValue[MAX_DISPLAY_VALUE_LENGTH];
    }* constData2 = (void*) (constDataBuffer + 1 + constData->displayKeyLen);
    VALIDATE(constData2->displayValueLen < MAX_DISPLAY_VALUE_LENGTH - 1, ERR_INVALID_DATA);
    VALIDATE(constSize == 2 + constData->displayKeyLen + constData2->displayValueLen,
             ERR_INVALID_DATA);
    VALIDATE(varSize == 0, ERR_INVALID_DATA);

    // Parsing
    // Prepare display variables ctx->key, ctx->value
    {
        STATIC_ASSERT(SIZEOF(ctx->key) >= SIZEOF(constData->displayKey),
                      "Display buffer too small");
        STATIC_ASSERT(SIZEOF(ctx->value) >= SIZEOF(constData2->displayValue),
                      "Display buffer too small");
        str_validateTextBuffer(constData->displayKey, constData->displayKeyLen);
        str_validateTextBuffer(constData2->displayValue, constData2->displayValueLen);
        memmove(ctx->key, constData->displayKey, constData->displayKeyLen);
        ctx->key[constData->displayKeyLen] = 0;
        memmove(ctx->value, constData2->displayValue, constData2->displayValueLen);
        ctx->value[constData2->displayValueLen] = 0;
    }

    // Reading data finished, from now on we use G_io_apdu_buffer for output

    // Append data to hash (none) and prepare response (none)
    { ctx->responseLength = 0; }

    // Run ui step
    ctx->ui_step = HANDLE_SIMPLE_STEP_DISPLAY_DETAILS;
    signTx_ui_runStep_simple();
}

// ======================= APPEND DATA ===========================

__noinline_due_to_stack__ void signTx_handleAppendDataAPDU(uint8_t p2,
                                                           uint8_t* constDataBuffer,
                                                           size_t constSize,
                                                           uint8_t* varDataBuffer,
                                                           size_t varSize) {
    // Sanity checks and trace buffers
    TRACE_STACK_USAGE();
    {
        VALIDATE(p2 == P2_UNUSED, ERR_INVALID_REQUEST_PARAMETERS);
        TRACE_BUFFER(constDataBuffer, constSize);
        TRACE_BUFFER(varDataBuffer, varSize);
    }

    // Data format
    struct {
        uint8_t valueFormat;
        uint8_t valueValidation;
        uint8_t valueValidationArg1[8];
        uint8_t valueValidationArg2[8];
        uint8_t valuePolicyAndStorage;
        uint8_t displayKeyLen;
        uint8_t displayKey[MAX_DISPLAY_KEY_LENGTH];
    }* constData = (void*) constDataBuffer;
    VALIDATE(constSize >= 20, ERR_INVALID_DATA);
    VALIDATE(constData->displayKeyLen <= MAX_DISPLAY_KEY_LENGTH - 1, ERR_INVALID_DATA);
    VALIDATE(constSize == 20 + constData->displayKeyLen, ERR_INVALID_DATA);
    struct {
        uint8_t value[MAX_TX_APPEND_IN_SINGLE_APDU];
    }* varData = (void*) varDataBuffer;
    VALIDATE(varSize <= MAX_TX_APPEND_IN_SINGLE_APDU, ERR_INVALID_DATA);

    // Storage validation
    {
        tx_storage_check_t storage = constData->valuePolicyAndStorage & 0xF0;
        TRACE("Storage request :%d, Stored length %d,%d,%d",
              (int) storage / 0x10,
              (int) ctx->storage.storedValueLen1,
              (int) ctx->storage.storedValueLen2,
              (int) ctx->storage.storedValueLen3);
        TRACE("Initialized: %d", ctx->storage.initialized_magic);
        switch (storage) {
#define CASE_STORAGE_EQUALS(n)                                                                     \
    case VALUE_STORAGE_CHECK_R##n: {                                                               \
        ASSERT(ctx->storage.initialized_magic == TX_STORAGE_INITIALIZED_MAGIC);                    \
        ASSERT(ctx->storage.storedValueLen##n <= sizeof(ctx->storage.storedValue##n));             \
        VALIDATE(ctx->storage.storedValueLen##n == varSize, ERR_INVALID_DATA);                     \
        VALIDATE(!memcmp(ctx->storage.storedValue##n, varData->value, varSize), ERR_INVALID_DATA); \
        break;                                                                                     \
    }
            CASE_STORAGE_EQUALS(1);
            CASE_STORAGE_EQUALS(2);
            CASE_STORAGE_EQUALS(3);
            case VALUE_STORAGE_CHECK_R1_DECODE_NAME: {
                ASSERT(ctx->storage.initialized_magic == TX_STORAGE_INITIALIZED_MAGIC);
                ASSERT(ctx->storage.storedValueLen1 <= sizeof(ctx->storage.storedValue1));
                char buffer[14];
                uint8array_name_to_string(ctx->storage.storedValue1,
                                          ctx->storage.storedValueLen1,
                                          buffer,
                                          SIZEOF(buffer));
                VALIDATE(varSize < SIZEOF(buffer), ERR_INVALID_DATA);
                TRACE("%s", buffer);
                TRACE("%s", varData->value);
                TRACE("%d", varSize);
                VALIDATE(buffer[varSize] == 0, ERR_INVALID_DATA);
                VALIDATE(!memcmp(buffer, varData->value, varSize), ERR_INVALID_DATA);
                break;
            }
            case VALUE_STORAGE_CHECK_NO:
                break;
            default:
                THROW(ERR_INVALID_DATA);
#undef CASE_STORAGE_EQUALS
        }
    }

    // Parsing ctx->dataToAppendToTx, ctx->dataToAppendToTxLen
    // Prepare display variables ctx->key, ctx->value, policy
    security_policy_t policy = POLICY_DENY;
    {
        str_validateTextBuffer(constData->displayKey, constData->displayKeyLen);
        ASSERT(SIZEOF(ctx->key) >= constData->displayKeyLen + 1);
        memcpy(ctx->key, constData->displayKey, constData->displayKeyLen);
        ctx->key[constData->displayKeyLen] = 0;

        parseValueToDisplay(constData->valueFormat,
                            constData->valueValidation,
                            constData->valueValidationArg1,
                            constData->valueValidationArg2,
                            varData->value,
                            varSize,
                            ctx->value);

        ASSERT(SIZEOF(ctx->dataToAppendToTx) >= varSize);
        memcpy(ctx->dataToAppendToTx, varData->value, varSize);
        ctx->dataToAppendToTxLen = varSize;

        policy = constData->valuePolicyAndStorage & 0x0F;
    }

    // Reading data finished, from now on we use G_io_apdu_buffer for output

    // Append data to hash (with possible DH encryption) and prepare response
    {
        VALIDATE(countedSectionProcess(&ctx->countedSections, varSize), ERR_INVALID_DATA);
        processShaAndPosibleDHAndPrepareResponse();
    }

    // Policy
    {
        TRACE("Policy %d", (int) policy);
        switch (policy) {
#define CASE(POLICY, UI_STEP)   \
    case POLICY: {              \
        ctx->ui_step = UI_STEP; \
        break;                  \
    }
            CASE(POLICY_ALLOW_WITHOUT_PROMPT, HANDLE_SIMPLE_STEP_RESPOND);
            CASE(POLICY_SHOW_BEFORE_RESPONSE, HANDLE_SIMPLE_STEP_DISPLAY_DETAILS);
            CASE(POLICY_SHOW_BEFORE_RESPONSE_IF_NONEMPTY,
                 strnlen(ctx->value, SIZEOF(ctx->value)) == 0 ? HANDLE_SIMPLE_STEP_RESPOND
                                                              : HANDLE_SIMPLE_STEP_DISPLAY_DETAILS)
            default:
                THROW(ERR_NOT_IMPLEMENTED);
#undef CASE
        }
    }

    // Run ui step
    signTx_ui_runStep_simple();
}

// ======================= START COUNTED SECTION ===========================

__noinline_due_to_stack__ void signTx_handleStartCountedSectionAPDU(uint8_t p2,
                                                                    uint8_t* constDataBuffer,
                                                                    size_t constSize,
                                                                    uint8_t* varDataBuffer,
                                                                    size_t varSize) {
    // Sanity checks and trace buffers
    TRACE_STACK_USAGE();
    {
        VALIDATE(p2 == P2_UNUSED, ERR_INVALID_REQUEST_PARAMETERS);
        TRACE_BUFFER(constDataBuffer, constSize);
        TRACE_BUFFER(varDataBuffer, varSize);
    }

    // Data format
    struct {
        uint8_t valueFormat;
        uint8_t valueValidation;
        uint8_t valueValidationArg1[8];
        uint8_t valueValidationArg2[8];
    }* constData = (void*) constDataBuffer;
    VALIDATE(constSize == SIZEOF(*constData), ERR_INVALID_DATA);
    struct {
        uint8_t value[MAX_TX_APPEND_IN_SINGLE_APDU];
    }* varData = (void*) varDataBuffer;
    VALIDATE(varSize <= MAX_TX_APPEND_IN_SINGLE_APDU, ERR_INVALID_DATA);

    // Parse data numberOfExpectedBytes, ctx->dataToAppendToTx, ctx->dataToAppendToTxLen
    uint32_t numberOfExpectedBytes = 0;
    {
        uint64_t value = 0;
        parseValueToUInt64(constData->valueFormat,
                           constData->valueValidation,
                           constData->valueValidationArg1,
                           constData->valueValidationArg2,
                           varData->value,
                           varSize,
                           &value);
        VALIDATE(value <= UINT32_MAX, ERR_INVALID_DATA);  // to fit into uint32_t
        numberOfExpectedBytes = value;

        memcpy(ctx->dataToAppendToTx, varData->value, varSize);
        ctx->dataToAppendToTxLen = varSize;
    }

    // Preparing display variables ctx->key, ctx->value
    {
        ctx->key[0] = 0;
        ctx->value[0] = 0;
    }

    // Reading data finished, from now on we use G_io_apdu_buffer for output

    // Append data to hash (with possible DH encryption) and prepare response, begin counted section
    {
        // this data does not count towards new counted section but counts towards old ones
        VALIDATE(countedSectionProcess(&ctx->countedSections, ctx->dataToAppendToTxLen),
                 ERR_INVALID_DATA);
        VALIDATE(countedSectionBegin(&ctx->countedSections, numberOfExpectedBytes),
                 ERR_INVALID_DATA);
        processShaAndPosibleDHAndPrepareResponse();
    }

    // Run ui step
    ctx->ui_step = HANDLE_SIMPLE_STEP_RESPOND;
    signTx_ui_runStep_simple();
}

// ======================= END COUNTED SECTION ===========================

__noinline_due_to_stack__ void signTx_handleEndCountedSectionAPDU(
    uint8_t p2,
    MARK_UNUSED_NO_DEVEL uint8_t* constDataBuffer,
    size_t constSize,
    MARK_UNUSED_NO_DEVEL uint8_t* varDataBuffer,
    size_t varSize) {
    // Sanity checks and trace buffers
    TRACE_STACK_USAGE();
    {
        VALIDATE(p2 == P2_UNUSED, ERR_INVALID_REQUEST_PARAMETERS);
        TRACE_BUFFER(constDataBuffer, constSize);
        TRACE_BUFFER(varDataBuffer, varSize);
    }

    // Data format
    VALIDATE(constSize == 0, ERR_INVALID_DATA);
    VALIDATE(varSize == 0, ERR_INVALID_DATA);

    // Preparing display variables ctx->key, ctx->value
    {
        ctx->key[0] = 0;
        ctx->value[0] = 0;
    }

    // Reading data finished, from now on we use G_io_apdu_buffer for output

    // Apend data to hash (no data) and response (none)
    {
        // Counted section that started before DH encoding cannot end within DH encoding
        if (ctx->dhIsActive) {
            VALIDATE(ctx->dhCountedSectionEntryLevel < ctx->countedSections.currentLevel,
                     ERR_INVALID_STATE);
        }
        VALIDATE(countedSectionEnd(&ctx->countedSections), ERR_INVALID_DATA);
        ctx->responseLength = 0;
    }

    // Run ui step
    ctx->ui_step = HANDLE_SIMPLE_STEP_RESPOND;
    signTx_ui_runStep_simple();
}

// ======================= STORE_VALUE ===========================

__noinline_due_to_stack__ void signTx_handleStoreValueAPDU(
    uint8_t p2,
    MARK_UNUSED_NO_DEVEL uint8_t* constDataBuffer,
    size_t constSize,
    uint8_t* varDataBuffer,
    size_t varSize) {
    // Sanity checks and trace buffers
    TRACE_STACK_USAGE();
    {
        VALIDATE(1 <= p2 && p2 <= 3, ERR_INVALID_REQUEST_PARAMETERS);  // we have 3 registers
        TRACE("Storing to %d", (int) p2);
        TRACE_BUFFER(constDataBuffer, constSize);
        TRACE_BUFFER(varDataBuffer, varSize);
    }

    // Data format
    VALIDATE(constSize == 0, ERR_INVALID_DATA);
    struct {
        uint8_t value[MAX_TX_APPEND_IN_SINGLE_APDU];
    }* varData = (void*) varDataBuffer;
    // varSize validated in Storage section

    // Storage
    {
        switch (p2) {
#define CASE(n)                                                                     \
    case n: {                                                                       \
        ASSERT(ctx->storage.initialized_magic == TX_STORAGE_INITIALIZED_MAGIC);     \
        VALIDATE(varSize <= sizeof(ctx->storage.storedValue##n), ERR_INVALID_DATA); \
        ctx->storage.storedValueLen##n = varSize;                                   \
        memcpy(ctx->storage.storedValue##n, varData->value, varSize);               \
        break;                                                                      \
    }
            CASE(1);
            CASE(2);
            CASE(3);
            default:
                THROW(ERR_NOT_IMPLEMENTED);
#undef CASE
        }
    }

    // Preparing display variables ctx->key, ctx->value
    {
        ctx->key[0] = 0;
        ctx->value[0] = 0;
    }

    // Reading data finished, from now on we use G_io_apdu_buffer for output

    // Apend data to hash (no data) and response (no data)
    { ctx->responseLength = 0; }

    // Run ui step
    ctx->ui_step = HANDLE_SIMPLE_STEP_RESPOND;
    signTx_ui_runStep_simple();
}

// ======================= START DH ENCODING ===========================
enum {
    HANDLE_DH_START_STEP_DISPLAY_MESSAGE = 800,
    HANDLE_DH_START_STEP_RESPOND,
    HANDLE_DH_START_STEP_INVALID,
};

static void signTx_handleDHStart_ui_runStep() {
    TRACE("UI step %d", ctx->ui_step);
    TRACE_STACK_USAGE();
    ui_callback_fn_t* this_fn = signTx_handleDHStart_ui_runStep;

    UI_STEP_BEGIN(ctx->ui_step, this_fn);

    UI_STEP(HANDLE_DH_START_STEP_DISPLAY_MESSAGE) {
        ui_displayPaginatedText("Encrypting", "content", this_fn);
    }

    UI_STEP(HANDLE_DH_START_STEP_RESPOND) {
        io_send_buf(SUCCESS, G_io_apdu_buffer, ctx->responseLength);
        ui_displayBusy();  // needs to happen after I/O
    }

    UI_STEP_END(HANDLE_DH_START_STEP_INVALID);
}

__noinline_due_to_stack__ void signTx_handleStartDHEncodingAPDU(
    uint8_t p2,
    MARK_UNUSED_NO_DEVEL uint8_t* constDataBuffer,
    size_t constSize,
    uint8_t* varDataBuffer,
    size_t varSize) {
    // Sanity checks and trace buffers
    TRACE_STACK_USAGE();
    {
        VALIDATE(p2 == P2_UNUSED, ERR_INVALID_REQUEST_PARAMETERS);
        TRACE_BUFFER(constDataBuffer, constSize);
        TRACE_BUFFER(varDataBuffer, varSize);
    }

    // Data format
    VALIDATE(constSize == 0, ERR_INVALID_DATA);
    struct {
        uint8_t pubkey[PUBKEY_LENGTH];
    }* varData = (void*) varDataBuffer;
    VALIDATE(varSize == PUBKEY_LENGTH, ERR_INVALID_DATA);

    // Parse data ctx->otherPubkey
    {
        cx_err_t err = cx_ecfp_init_public_key_no_throw(CX_CURVE_SECP256K1,
                                                        varData->pubkey,
                                                        SIZEOF(varData->pubkey),
                                                        &ctx->otherPubkey);
        VALIDATE(err == CX_OK, ERR_INVALID_DATA);
    }

    // Preparing display variables ctx->key, ctx->value
    {
        TRACE_STACK_USAGE();
        snprintf(ctx->key, MAX_DISPLAY_KEY_LENGTH, "Their Public Key");
        uint32_t outlen = public_key_to_wif(ctx->otherPubkey.W,
                                            SIZEOF(ctx->otherPubkey.W),
                                            ctx->value,
                                            SIZEOF(ctx->value));
        ASSERT(outlen > 0);
        ASSERT(outlen < SIZEOF(ctx->value));
        ctx->value[outlen] = 0;
    }

    // Reading data finished, from now on we use G_io_apdu_buffer for output

    // Init DH Encoding
    // Append encrypted data to hash and response
    {
        TRACE_STACK_USAGE();
        VALIDATE(!ctx->dhIsActive, ERR_INVALID_STATE);

        TRACE_STACK_USAGE();
        // Generate IV
        uint8_t IV[DH_AES_IV_SIZE];
        cx_rng_no_throw(IV, SIZEOF(IV));

        // INIT dh context
        STATIC_ASSERT(DH_AES_IV_SIZE == CX_AES_BLOCK_SIZE, "Unexpected IV length");
        ctx->dhCountedSectionEntryLevel = ctx->countedSections.currentLevel;
        uint16_t bufferLen = SIZEOF(G_io_apdu_buffer);

        uint16_t err = dh_encode_init(&ctx->dhContext,
                                      &ctx->witnessPath,
                                      &ctx->otherPubkey,
                                      IV,
                                      SIZEOF(IV),
                                      G_io_apdu_buffer,
                                      &bufferLen);
        if (err != SUCCESS) {
            THROW(err);
        }
        ctx->responseLength = bufferLen;
        if (ctx->responseLength != 20) {  // first 5 blocks
            THROW(ERR_ASSERT);
        }
        ctx->countedSectionDifference = ctx->responseLength;
        TRACE("CS diff %d", (int) ctx->responseLength);

        ASSERT(sha_256_append(&ctx->hashContext, G_io_apdu_buffer, ctx->responseLength) == CX_OK);
        ctx->dhIsActive = true;
    }

    // Run ui step
    ctx->ui_step = HANDLE_DH_START_STEP_DISPLAY_MESSAGE;
    signTx_handleDHStart_ui_runStep();
}

// ======================= END DH ENCODING ===========================

enum {
    HANDLE_DH_END_STEP_CONFIRM = 900,
    HANDLE_DH_END_STEP_RESPOND,
    HANDLE_DH_END_STEP_INVALID,
};

static void signTx_handleDHEnd_ui_runStep() {
    TRACE("UI step %d", ctx->ui_step);
    TRACE_STACK_USAGE();
    ui_callback_fn_t* this_fn = signTx_handleDHEnd_ui_runStep;

    UI_STEP_BEGIN(ctx->ui_step, this_fn);

    UI_STEP(HANDLE_DH_END_STEP_CONFIRM) {
        ui_displayPrompt("Encrypt content?", "", this_fn, respond_with_user_reject);
    }

    UI_STEP(HANDLE_DH_END_STEP_RESPOND) {
        io_send_buf(SUCCESS, G_io_apdu_buffer, ctx->responseLength);
        ui_displayBusy();  // needs to happen after I/O
    }

    UI_STEP_END(HANDLE_DH_END_STEP_INVALID);
}

__noinline_due_to_stack__ void signTx_handleEndDHEncodingAPDU(
    uint8_t p2,
    MARK_UNUSED_NO_DEVEL uint8_t* constDataBuffer,
    size_t constSize,
    MARK_UNUSED_NO_DEVEL uint8_t* varDataBuffer,
    size_t varSize) {
    // Sanity checks and trace buffers
    TRACE_STACK_USAGE();
    {
        VALIDATE(p2 == P2_UNUSED, ERR_INVALID_REQUEST_PARAMETERS);
        TRACE_BUFFER(constDataBuffer, constSize);
        TRACE_BUFFER(varDataBuffer, varSize);
    }

    // Data format
    {
        VALIDATE(constSize == 0, ERR_INVALID_DATA);
        VALIDATE(varSize == 0, ERR_INVALID_DATA);
    }

    // Preparing display variables ctx->key, ctx->value
    {
        snprintf(ctx->key, MAX_DISPLAY_KEY_LENGTH, "Our Public Key");
        prepareOurPubkeyForDisplay();
    }

    // Reading data finished, from now on we use G_io_apdu_buffer for output
    {
        // Apend data to hash (final blocks of DH encryption) and prepare response
        {
            // To be sure that we are encoding correct DH data
            VALIDATE(integrityCheckEvaluate(&ctx->integrity), ERR_INTEGRITY_CHECK_FAILED);

            VALIDATE(ctx->dhIsActive, ERR_INVALID_STATE);
            // Counted section that started within DH encoding cannot end after DH encoding
            VALIDATE(ctx->dhCountedSectionEntryLevel == ctx->countedSections.currentLevel,
                     ERR_INVALID_STATE);

            uint16_t bufferLen = SIZEOF(G_io_apdu_buffer);
            uint16_t err = dh_encode_finalize(&ctx->dhContext,
                                              &ctx->witnessPath,
                                              &ctx->otherPubkey,
                                              G_io_apdu_buffer,
                                              &bufferLen);
            if (err != SUCCESS) {
                explicit_bzero(G_io_apdu_buffer, SIZEOF(G_io_apdu_buffer));
                THROW(err);
            }
            ctx->responseLength = bufferLen;

            ctx->countedSectionDifference += ctx->responseLength;
            TRACE("CS diff %d from:%d",
                  (int) ctx->countedSectionDifference,
                  (int) ctx->responseLength);
            VALIDATE(countedSectionProcess(&ctx->countedSections, ctx->countedSectionDifference),
                     ERR_INVALID_STATE);

            ASSERT(sha_256_append(&ctx->hashContext, G_io_apdu_buffer, ctx->responseLength) ==
                   CX_OK);
            ctx->dhIsActive = false;
        }

        // Security policy
        {
            security_policy_t policy = POLICY_DENY;
            policy = policyForSignTxDHEnd();
            TRACE("Policy: %d", (int) policy);
            ENSURE_NOT_DENIED(policy);
            // select UI step
            if (policy == POLICY_PROMPT_BEFORE_RESPONSE) {
                ctx->ui_step = HANDLE_DH_END_STEP_CONFIRM;
            } else {
                THROW(ERR_NOT_IMPLEMENTED);
            }
        }
    }

    signTx_handleDHEnd_ui_runStep();
}

// ============================== FINISH ==============================

enum {
    HANDLE_FINISH_STEP_DISPLAY_DETAILS = 1000,
    HANDLE_FINISH_STEP_CONFIRM,
    HANDLE_FINISH_STEP_RESPOND,
    HANDLE_FINISH_STEP_INVALID,
};

static void signTx_handleFinish_ui_runStep() {
    TRACE("UI step %d", ctx->ui_step);
    TRACE_STACK_USAGE();
    ui_callback_fn_t* this_fn = signTx_handleFinish_ui_runStep;

    UI_STEP_BEGIN(ctx->ui_step, this_fn);

    UI_STEP(HANDLE_FINISH_STEP_DISPLAY_DETAILS) {
        ui_displayPaginatedText(ctx->key, ctx->value, this_fn);
    }

    UI_STEP(HANDLE_FINISH_STEP_CONFIRM) {
        ui_displayPrompt("Sign", "transaction?", this_fn, respond_with_user_reject);
    }

    UI_STEP(HANDLE_FINISH_STEP_RESPOND) {
        io_send_buf(SUCCESS, G_io_apdu_buffer, PUBKEY_LENGTH + SHA_256_SIZE);
        ui_displayBusy();  // needs to happen after I/O
        ui_idle();         // we are done with this tx
    }

    UI_STEP_END(HANDLE_FINISH_STEP_INVALID);
}

__noinline_due_to_stack__ void signTx_handleFinishAPDU(
    uint8_t p2,
    MARK_UNUSED_NO_DEVEL uint8_t* constDataBuffer,
    size_t constSize,
    MARK_UNUSED_NO_DEVEL uint8_t* varDataBuffer,
    size_t varSize) {
    // Sanity checks and trace buffers
    TRACE_STACK_USAGE();
    {
        VALIDATE(p2 == P2_UNUSED, ERR_INVALID_REQUEST_PARAMETERS);
        TRACE_BUFFER(constDataBuffer, constSize);
        TRACE_BUFFER(varDataBuffer, varSize);
    }

    // Data format
    {
        VALIDATE(constSize == 0, ERR_INVALID_DATA);
        VALIDATE(varSize == 0, ERR_INVALID_DATA);
    }

    // Preparing display variables ctx->key, ctx->value
    {
        snprintf(ctx->key, MAX_DISPLAY_KEY_LENGTH, "Sign with");
        prepareOurPubkeyForDisplay();
    }

    // Reading data finished, from now on we use G_io_apdu_buffer for output

    // Hash - this is the last call, we finalize it + counted sections
    uint8_t hashBuf[SHA_256_SIZE];
    explicit_bzero(hashBuf, SIZEOF(hashBuf));
    {
        ASSERT(sha_256_finalize(&ctx->hashContext, hashBuf, SIZEOF(hashBuf)) == CX_OK);
        TRACE("SHA_256_finalize, resulting hash:");
        TRACE_BUFFER(hashBuf, SHA_256_SIZE);
    }

    // This is the last call - we need to check integrity of the command sequence + just for good
    // measures we finalize counted section
    {
        VALIDATE(!ctx->dhIsActive, ERR_INVALID_STATE);
        VALIDATE(integrityCheckEvaluate(&ctx->integrity), ERR_INTEGRITY_CHECK_FAILED);
        VALIDATE(countedSectionFinalize(&ctx->countedSections), ERR_INVALID_DATA);
    }

    // Security policy
    security_policy_t policy = POLICY_DENY;
    {
        policy = policyForSignTxFinish();
        TRACE("Policy: %d", (int) policy);
        ENSURE_NOT_DENIED(policy);
        // select UI step
        if (policy == POLICY_PROMPT_BEFORE_RESPONSE) {
            ctx->ui_step = HANDLE_FINISH_STEP_DISPLAY_DETAILS;
        } else {
            THROW(ERR_NOT_IMPLEMENTED);
        }
    }

    uint16_t err =
        signTransaction(&ctx->witnessPath, hashBuf, G_io_apdu_buffer, SIZEOF(G_io_apdu_buffer));
    if (err != SUCCESS) {
        explicit_bzero(G_io_apdu_buffer, SIZEOF(G_io_apdu_buffer));
        THROW(err);
    }

    // We add hash to the response
    TRACE_BUFFER(G_io_apdu_buffer, PUBKEY_LENGTH);
    STATIC_ASSERT(SIZEOF(G_io_apdu_buffer) >= PUBKEY_LENGTH + SIZEOF(hashBuf),
                  "G_io_apdu_buffer too small");
    memcpy(G_io_apdu_buffer + PUBKEY_LENGTH, hashBuf, SIZEOF(hashBuf));

    signTx_handleFinish_ui_runStep();
}

// ============================== MAIN HANDLER ==============================

typedef void subhandler_fn_t(uint8_t p2,
                             uint8_t* constDataBuffer,
                             size_t constSize,
                             uint8_t* varDataBuffer,
                             size_t varSize);

static subhandler_fn_t* lookup_subhandler(uint8_t p1) {
    switch (p1) {
#define CASE(P1, HANDLER) \
    case P1:              \
        return HANDLER;
#define DEFAULT(HANDLER) \
    default:             \
        return HANDLER;
        CASE(0x01, signTx_handleInitAPDU);
        CASE(0x02, signTx_handleAppendConstDataAPDU);
        CASE(0x03, signTx_handleShowMessageAPDU);
        CASE(0x04, signTx_handleAppendDataAPDU);
        CASE(0x05, signTx_handleStartCountedSectionAPDU);
        CASE(0x06, signTx_handleEndCountedSectionAPDU);
        CASE(0x07, signTx_handleStoreValueAPDU);
        CASE(0x08, signTx_handleStartDHEncodingAPDU);
        CASE(0x09, signTx_handleEndDHEncodingAPDU);
        CASE(0x10, signTx_handleFinishAPDU);
        DEFAULT(NULL)
#undef CASE
#undef DEFAULT
    }
}

void signTransaction_handleAPDU(uint8_t p1,
                                uint8_t p2,
                                uint8_t* wireDataBuffer,
                                size_t wireDataSize,
                                bool isNewCall) {
    TRACE("P1 = 0x%x, P2 = 0x%x, isNewCall = %d", p1, p2, isNewCall);
    TRACE_STACK_USAGE();

    if (isNewCall) {
        explicit_bzero(ctx, SIZEOF(*ctx));
        TRACE("SHA_256_init");
        cx_err_t err = sha_256_init(&ctx->hashContext);
        ASSERT(err == CX_OK);
        TRACE("Integrity check init");
        integrityCheckInit(&ctx->integrity);
        TRACE("Counted sections init");
        countedSectionInit(&ctx->countedSections);
        TRACE("Storage init");
        explicit_bzero(&ctx->storage, SIZEOF(ctx->storage));
        ctx->storage.initialized_magic = TX_STORAGE_INITIALIZED_MAGIC;
        TRACE("DH inactive");
        ctx->dhIsActive = false;
        ctx->initWasCalledMagic = TX_INIT_WAS_CALLED_INITIALIZED_MAGIC;
    }
    VALIDATE(TX_INIT_WAS_CALLED_INITIALIZED_MAGIC, ERR_INVALID_DATA);

    // Parse APDU into const and non-const part
    ASSERT(wireDataSize < BUFFER_SIZE_PARANOIA);
    VALIDATE(wireDataSize >= 2, ERR_INVALID_DATA);
    uint8_t constantDataLen = wireDataBuffer[0];
    uint8_t variableDataLen = wireDataBuffer[1];
    VALIDATE(wireDataSize >= (size_t) 2 + constantDataLen + variableDataLen, ERR_INVALID_DATA);
    uint8_t* constantData = wireDataBuffer + 2;
    uint8_t* variableData = constantData + constantDataLen;

    {
        // Update integrity and transaction hash
        integrityCheckProcessInstruction(&ctx->integrity, p1, p2, constantData, constantDataLen);
    }

    subhandler_fn_t* subhandler = lookup_subhandler(p1);
    VALIDATE(subhandler != NULL, ERR_INVALID_REQUEST_PARAMETERS);

    subhandler(p2, constantData, constantDataLen, variableData, variableDataLen);
}
