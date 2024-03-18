#ifndef H_FIO_APP_DECODE_DH
#define H_FIO_APP_DECODE_DH

#include "handlers.h"
#include "bip44.h"
#include "keyDerivation.h"

#define MAX_MESSAGE_LENGTH 324

typedef enum {
    DECODE_STAGE_NONE = 0,
    DECODE_STAGE_RECEIVE_DATA = 1,
    DECODE_STAGE_DECODE = 2,
    DECODE_STAGE_SEND_REST = 3,
} decode_stage_t;

typedef struct {
    uint8_t length;
    uint8_t data[];
} string_with_length_t;

// These pointers will point to decoded message where strings are stored in string_with_length_t
// format
typedef struct {
    string_with_length_t *payee_public_address;
    string_with_length_t *payer_public_address;
    string_with_length_t *amount;
    string_with_length_t *chain_code;
    string_with_length_t *token_code;
    string_with_length_t *status;
    string_with_length_t *obt_id;
    string_with_length_t *memo;
    string_with_length_t *hash;
    string_with_length_t *offline_url;
} parsed_context_t;

typedef struct {
    decode_stage_t stage;

    bip44_path_t pathSpec;
    public_key_t otherPubKey;
    uint16_t bufferLen;
    uint16_t bufferSentLen;
    uint8_t buffer[MAX_MESSAGE_LENGTH];

    uint16_t messageDecodedMagic;

    int ui_step;

    parsed_context_t parsedContent;
} ins_decode_context_t;

handler_fn_t decode_handleAPDU;

#endif  // H_FIO_DECODE_DH
