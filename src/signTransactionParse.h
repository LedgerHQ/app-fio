#ifndef H_FIO_APP_SIGN_TRANSACTION_PARSE
#define H_FIO_APP_SIGN_TRANSACTION_PARSE
#include <stdint.h>
#include "signTransaction.h"

typedef enum {
    VALUE_FORMAT_UNKNOWN = 0x00,

    // String types
    VALUE_FORMAT_BUFFER_SHOW_AS_HEX = 0x01,
    VALUE_FORMAT_ASCII_STRING = 0x02,
    VALUE_FORMAT_NAME = 0x03,
    VALUE_FORMAT_ASCII_STRING_WITH_LENGTH = 0x04,

    // Number
    VALUE_FORMAT_FIO_AMOUNT = 0x10,
    VALUE_FORMAT_UINT64 = 0x14,
    VALUE_FORMAT_VARUINT32 = 0x17,

    // Special
    VALUE_FORMAT_MEMO_HASH = 0x20,
    VALUE_FORMAT_CHAIN_CODE_TOKEN_CODE_PUBLIC_ADDR = 0x21,
} value_format_t;

typedef enum {
    VALUE_VALIDATION_UNKNOWN = 0,
    VALUE_VALIDATION_NONE = 1,
    VALUE_VALIDATION_INBUFFER_LENGTH = 2,

    VALUE_VALIDATION_NUMBER = 3,
} value_buffer_validation_t;

void parseValueToDisplay(value_format_t format,
                         value_buffer_validation_t validation,
                         uint8_t argument1[8],
                         uint8_t argument2[8],
                         const uint8_t *value,
                         uint8_t valueLen,
                         char display[MAX_DISPLAY_VALUE_LENGTH]);

void parseValueToUInt64(value_format_t format,
                        value_buffer_validation_t validation,
                        uint8_t argument1[8],
                        uint8_t argument2[8],
                        const uint8_t *value,
                        uint8_t valueLen,
                        uint64_t *number);

#endif  // H_FIO_APP_SIGN_TRANSACTION_PARSE
