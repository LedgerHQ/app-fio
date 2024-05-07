#include "common.h"
#include "signTransactionParse.h"
#include "hexUtils.h"
#include "textUtils.h"
#include "fio.h"

static bool isNumberType(value_format_t format) {
    return (format >= 0x10 && format < 0x20);
}

// Returns number of bytes read
// Based on:
// https://github.com/fioprotocol/fiojs/blob/10848a02983a4b5b7f185c90bc96fb78e9ab0a6f/src/chain-serialize.ts#L259
// As of my understanding, allowed values are between 0 and UINT32_MAX
static uint8_t getNumberFromVarUInt(const uint8_t *value, uint8_t valueLen, uint64_t *number) {
    ASSERT(number != NULL);
    uint8_t bitShift = 0;
    uint8_t readPosition = 0;
    *number = 0;

    while (true) {
        VALIDATE(readPosition < valueLen, ERR_INVALID_DATA);
        uint8_t nextByte = value[readPosition];
        *number |= ((uint64_t) (nextByte & 0x7f)) << bitShift;
        bitShift += 7;
        readPosition++;
        TRACE("readPosition: %d, nextByte:%d, Value read: %d,%d",
              (int) readPosition,
              (int) nextByte,
              (int) ((*number) / 0x100000000),
              (int) *(number));
        if (!(nextByte & 0x80)) {
            break;
        }
        VALIDATE(readPosition < 9,
                 ERR_INVALID_DATA);  // if we read more than 9 values we will owerflow uint64
    }

    TRACE("VarUInt conversion: Value read: %d,%d, Number of bytes: %d",
          (int) ((*number) / 0x100000000),
          (int) *(number),
          (int) readPosition);

    return readPosition;
}

//-------------------- STRING PARSING AND DISPLAYING FUNCTIONS ----------------------

static void displayBufferShowAsHex(const uint8_t *value,
                                   uint8_t valueLen,
                                   char display[MAX_DISPLAY_VALUE_LENGTH]) {
    VALIDATE(valueLen * 2 < MAX_DISPLAY_VALUE_LENGTH, ERR_INVALID_DATA);
    size_t outlen = encode_hex(value, valueLen, display, MAX_DISPLAY_VALUE_LENGTH);
    ASSERT(outlen < MAX_DISPLAY_VALUE_LENGTH);
    display[outlen] = 0;
}

static void displayASCIIString(const uint8_t *value,
                               uint8_t valueLen,
                               char display[MAX_DISPLAY_VALUE_LENGTH]) {
    VALIDATE(valueLen < MAX_DISPLAY_VALUE_LENGTH, ERR_INVALID_DATA);
    str_validateTextBuffer(value, valueLen);
    memcpy(display, value, valueLen);
    display[valueLen] = 0;
}

static void displayName(const uint8_t *value,
                        uint8_t valueLen,
                        char display[MAX_DISPLAY_VALUE_LENGTH]) {
    VALIDATE(valueLen == NAME_VAR_LENGTH, ERR_INVALID_DATA);
    uint8array_name_to_string(value,
                              valueLen,
                              display,
                              MAX_DISPLAY_VALUE_LENGTH);  // null terminated, no return vallue
}

static void displayASCIIStringWithLength(const uint8_t *value,
                                         uint8_t valueLen,
                                         char display[MAX_DISPLAY_VALUE_LENGTH]) {
    uint64_t strLen = 0;
    uint8_t strLenLen = getNumberFromVarUInt(value, valueLen, &strLen);
    VALIDATE(strLen < MAX_DISPLAY_VALUE_LENGTH, ERR_INVALID_DATA);
    VALIDATE(valueLen == strLenLen + strLen, ERR_INVALID_DATA);
    str_validateTextBuffer(value + strLenLen, strLen);
    memcpy(display, value + strLenLen, strLen);
    display[strLen] = 0;
}

// helper for displayMemoHash
static bool validateOptional(const uint8_t *value, uint8_t valueLen, uint8_t *read) {
    VALIDATE(valueLen >= *read + 1, ERR_INVALID_DATA);
    uint8_t hasOptional = value[*read];
    if (hasOptional) {
        VALIDATE(hasOptional == 1, ERR_INVALID_DATA);
        VALIDATE(valueLen >= *read + 2, ERR_INVALID_DATA);
        uint8_t optionalLen = value[*read + 1];
        VALIDATE(optionalLen < 127, ERR_INVALID_DATA);
        *read += 2 + optionalLen;
        return true;
    } else {
        *read += 1;
        return false;
    }
}

static void displayMemoHash(const uint8_t *value,
                            uint8_t valueLen,
                            char display[MAX_DISPLAY_VALUE_LENGTH]) {
    // data format:
    // hasMemo(0x00/0x01), if yes then memolength (1b, < 127) and memo
    // hasHash(0x00/0x01), if yes then hashlength (1b, < 127) and hash
    // hasOfflineUrl(0x00/0x01), if yes then offlineurllength (1b, < 127) and offlineurl
    // hash and offline url have to be present at the same time.
    TRACE_BUFFER(value, valueLen);
    uint8_t read = 0;
    bool hasMemo = validateOptional(value, valueLen, &read);
    bool hasHash = validateOptional(value, valueLen, &read);
    bool hasOfflineUrl = validateOptional(value, valueLen, &read);
    VALIDATE((hasHash && hasOfflineUrl) || (!hasHash && !hasOfflineUrl), ERR_INVALID_DATA);
    // These data are not meant to e displayed at themoement
    snprintf(display, MAX_DISPLAY_VALUE_LENGTH, "NOT IMPLEMENTED");
}

static void displayChainCodeTokenCodePublicAddr(const uint8_t *value,
                                                uint8_t valueLen,
                                                char display[MAX_DISPLAY_VALUE_LENGTH]) {
    // Format: token code lenth (varUINT), token code, chain code length(varUINT), chain code,
    // publicAddrLen (varUINT), publicAddr
    TRACE_BUFFER(value, valueLen);
    VALIDATE(valueLen >= 1, ERR_INVALID_DATA);
    size_t tokenCodeLen = value[0];  // always just one byte as it needs to be <=10
    VALIDATE(1 <= tokenCodeLen && tokenCodeLen <= 10, ERR_INVALID_DATA);
    VALIDATE(valueLen >= tokenCodeLen + 2, ERR_INVALID_DATA);
    size_t chainCodeLen = value[tokenCodeLen + 1];  // always just one byte as it needs to be <=10
    VALIDATE(1 <= chainCodeLen && chainCodeLen <= 10, ERR_INVALID_DATA);
    VALIDATE(valueLen >= tokenCodeLen + chainCodeLen + 3, ERR_INVALID_DATA);
    uint64_t publicAddrLen = 0;
    size_t publicAddrLenLen = getNumberFromVarUInt(value + tokenCodeLen + chainCodeLen + 2,
                                                   valueLen - (tokenCodeLen + chainCodeLen + 2),
                                                   &publicAddrLen);
    size_t publicAddrStart = tokenCodeLen + chainCodeLen + 2 + publicAddrLenLen;
    VALIDATE(1 <= publicAddrLen && publicAddrLen <= 128, ERR_INVALID_DATA);
    VALIDATE(valueLen == publicAddrStart + publicAddrLen, ERR_INVALID_DATA);

    str_validateTextBuffer(value + 1, tokenCodeLen);
    str_validateTextBuffer(value + tokenCodeLen + 2, chainCodeLen);
    str_validateTextBuffer(value + publicAddrStart, publicAddrLen);

    // prepare to display
    ASSERT(tokenCodeLen + 1 + chainCodeLen + 1 + publicAddrLen < MAX_DISPLAY_VALUE_LENGTH);
    snprintf(display,
             MAX_DISPLAY_VALUE_LENGTH,
             "%.*s:%.*s:%.*s",
             (int) chainCodeLen,
             value + tokenCodeLen + 2,
             (int) tokenCodeLen,
             value + 1,
             (int) publicAddrLen,
             value + publicAddrStart);
}

//-------------------- NUMBER PARSING FUNCTIONS ----------------------

static void parseUInt64(const uint8_t *value, uint8_t valueLen, uint64_t *number) {
    VALIDATE(valueLen == sizeof(*number), ERR_INVALID_DATA);
    memcpy(number, value, sizeof(*number));
}

static void parseVarUInt32(const uint8_t *value, uint8_t valueLen, uint64_t *number) {
    uint8_t read = getNumberFromVarUInt(value, valueLen, number);
    VALIDATE(read == valueLen, ERR_INVALID_DATA);
    VALIDATE(*number <= UINT32_MAX, ERR_INVALID_DATA);
}

//-------------------- NUMBER VALIDATING FUNCTIONS ----------------------

static void validateNumber(value_buffer_validation_t validation,
                           uint64_t arg1,
                           uint64_t arg2,
                           uint64_t number) {
    if (validation == VALUE_VALIDATION_NUMBER) {
        VALIDATE(arg1 <= number && number <= arg2, ERR_INVALID_DATA);
    }
}

//-------------------- NUMBER DISPLAYING FUNCTIONS ----------------------

static void displayFioAmount(uint64_t amount, char display[MAX_DISPLAY_VALUE_LENGTH]) {
    size_t outlen = str_formatFIOAmount(amount, display, MAX_DISPLAY_VALUE_LENGTH);
    ASSERT(outlen < MAX_DISPLAY_VALUE_LENGTH);
    display[outlen] = 0;
}

static void displayNumber(uint64_t number, char display[MAX_DISPLAY_VALUE_LENGTH]) {
    size_t outlen = str_formatUint64(number, display, MAX_DISPLAY_VALUE_LENGTH);
    ASSERT(outlen < MAX_DISPLAY_VALUE_LENGTH);
    display[outlen] = 0;
}

//-------------------- BUFFER VALIDATION ----------------------

void bufferValidation(value_format_t format,
                      value_buffer_validation_t validation,
                      uint64_t arg1,
                      uint64_t arg2,
                      MARK_UNUSED const uint8_t *value,
                      uint8_t valueLen) {
    // buffer validation
    switch (validation) {
#define CASE(VALIDATION, condition)            \
    case VALIDATION: {                         \
        VALIDATE(condition, ERR_INVALID_DATA); \
        break;                                 \
    }
        CASE(VALUE_VALIDATION_NONE, arg1 == 0 && arg2 == 0);
        CASE(VALUE_VALIDATION_INBUFFER_LENGTH, arg1 <= valueLen && arg2 >= valueLen);
        CASE(VALUE_VALIDATION_NUMBER,
             isNumberType(format));  // number validation implies number type
        default:
            THROW(ERR_INVALID_DATA);
#undef CASE
    }
}

//-------------------- MAIN FUNCITONS ----------------------

void parseValueToUInt64(value_format_t format,
                        value_buffer_validation_t validation,
                        uint8_t argument1[8],
                        uint8_t argument2[8],
                        const uint8_t *value,
                        uint8_t valueLen,
                        uint64_t *number) {
    uint64_t arg1 = 0;
    uint64_t arg2 = 0;
    memcpy(&arg1, argument1, 8);
    memcpy(&arg2, argument2, 8);

    bufferValidation(format, validation, arg1, arg2, value, valueLen);

    switch (format) {
        case VALUE_FORMAT_FIO_AMOUNT: {
            parseUInt64(value, valueLen, number);
            validateNumber(validation, arg1, arg2, *number);
            break;
        }
        case VALUE_FORMAT_UINT64: {
            parseUInt64(value, valueLen, number);
            validateNumber(validation, arg1, arg2, *number);
            break;
        }
        case VALUE_FORMAT_VARUINT32: {
            parseVarUInt32(value, valueLen, number);
            validateNumber(validation, arg1, arg2, *number);
            break;
        }
        default:
            THROW(ERR_INVALID_DATA);
#undef CASE
    }
}

void parseValueToDisplay(value_format_t format,
                         value_buffer_validation_t validation,
                         uint8_t argument1[8],
                         uint8_t argument2[8],
                         const uint8_t *value,
                         uint8_t valueLen,
                         char display[MAX_DISPLAY_VALUE_LENGTH]) {
    uint64_t arg1 = 0;
    uint64_t arg2 = 0;
    memcpy(&arg1, argument1, 8);
    memcpy(&arg2, argument2, 8);

    bufferValidation(format, validation, arg1, arg2, value, valueLen);

    switch (format) {
        case VALUE_FORMAT_BUFFER_SHOW_AS_HEX:
            displayBufferShowAsHex(value, valueLen, display);
            break;
        case VALUE_FORMAT_ASCII_STRING:
            displayASCIIString(value, valueLen, display);
            break;
        case VALUE_FORMAT_NAME:
            displayName(value, valueLen, display);
            break;
        case VALUE_FORMAT_ASCII_STRING_WITH_LENGTH:
            displayASCIIStringWithLength(value, valueLen, display);
            break;
        case VALUE_FORMAT_FIO_AMOUNT: {
            uint64_t amount;
            parseUInt64(value, valueLen, &amount);
            validateNumber(validation, arg1, arg2, amount);
            displayFioAmount(amount, display);
            break;
        }
        case VALUE_FORMAT_UINT64: {
            uint64_t number;
            parseUInt64(value, valueLen, &number);
            validateNumber(validation, arg1, arg2, number);
            displayNumber(number, display);
            break;
        }
        case VALUE_FORMAT_VARUINT32: {
            uint64_t number;
            parseVarUInt32(value, valueLen, &number);
            validateNumber(validation, arg1, arg2, number);
            displayNumber(number, display);
            break;
        }
        case VALUE_FORMAT_MEMO_HASH: {
            displayMemoHash(value, valueLen, display);
            break;
        }
        case VALUE_FORMAT_CHAIN_CODE_TOKEN_CODE_PUBLIC_ADDR: {
            displayChainCodeTokenCodePublicAddr(value, valueLen, display);
            break;
        }
        default:
            THROW(ERR_INVALID_DATA);
#undef CASE
    }
}
