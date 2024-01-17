#include "cx.h"

unsigned char G_io_apdu_buffer[260];
unsigned int app_stack_canary = 0xDEAD0031;

void os_longjmp(unsigned int exception) {
    longjmp(try_context_get()->jmp_buf, exception);
}

try_context_t *current_context = NULL;
try_context_t *try_context_get(void) {
    return current_context;
}

try_context_t *try_context_set(try_context_t *ctx) {
    try_context_t *previous_ctx = current_context;
    current_context = ctx;
    return previous_ctx;
}

size_t cx_hash_get_size(const cx_hash_t *ctx) {
    return 32;
}

cx_err_t cx_sha256_init_no_throw(cx_sha256_t *hash) {
    return CX_OK;
}

cx_err_t cx_hash_no_throw(cx_hash_t *hash, uint32_t mode, const uint8_t *in, size_t len, uint8_t *out, size_t out_len) {
    return CX_OK;
}

cx_err_t cx_ecdsa_sign_no_throw(const cx_ecfp_private_key_t *pvkey,
                       uint32_t                     mode,
                       cx_md_t                      hashID,
                       const uint8_t *              hash,
                       size_t                       hash_len,
                       uint8_t *                    sig,
                       size_t *                     sig_len,
                       uint32_t *                   info){
    return CX_OK;
}

unsigned int os_serial(unsigned char *serial PLENGTH(maxlength),
                               unsigned int maxlength){
    return 7;
}

typedef enum bolos_ux_e {
  BOLOS_UX_INITIALIZE = 0,
  BOLOS_UX_EVENT,
  BOLOS_UX_KEYBOARD,
  BOLOS_UX_WAKE_UP,
  BOLOS_UX_VALIDATE_PIN = 14,
  BOLOS_UX_LAST_ID,
} bolos_ux_t;

typedef struct bolos_ux_params_s {
    bolos_ux_t ux_id;
    unsigned int len;
} bolos_ux_params_t;

unsigned int os_ux ( bolos_ux_params_t * params ) {
    return 1;
}

typedef unsigned char bolos_task_status_t;

bolos_task_status_t os_sched_last_status ( unsigned int task_idx ) {
    return 0;
}

typedef char bolos_bool_t;

bolos_bool_t os_perso_isonboarded ( void ) {
    return 1;
}

cx_err_t cx_ecfp_init_private_key_no_throw(cx_curve_t             curve,
                                  const uint8_t *        rawkey,
                                  size_t                 key_len,
                                  cx_ecfp_private_key_t *pvkey)
{
    return CX_OK;
}

cx_err_t cx_ecfp_init_public_key_no_throw(cx_curve_t            curve,
                                 const uint8_t *       rawkey,
                                 size_t                key_len,
                                 cx_ecfp_public_key_t *key)
{
    return CX_OK;
}

cx_err_t cx_ecfp_generate_pair_no_throw(cx_curve_t             curve,
                               cx_ecfp_public_key_t * pubkey,
                               cx_ecfp_private_key_t *privkey,
                               bool                   keepprivate)
{
    return CX_OK;
}

cx_err_t cx_hmac_sha256_init_no_throw(cx_hmac_sha256_t *hmac, const uint8_t *key, size_t key_len){
    //hmac->hash_ctx.header.info->md_type = 3;
    return CX_OK;
}

cx_err_t cx_hmac_no_throw(cx_hmac_t *hmac, uint32_t mode, const uint8_t *in, size_t len, uint8_t *mac, size_t mac_len){
    return CX_OK;
}

cx_err_t cx_ripemd160_init_no_throw(cx_ripemd160_t *hash){
    return CX_OK;
}

cx_err_t cx_ecdh_no_throw(const cx_ecfp_private_key_t *pvkey,
                 uint32_t                     mode,
                 const uint8_t *              P,
                 size_t                       P_len,
                 uint8_t *                    secret,
                 size_t                       secret_len) {
    return CX_OK;
}

cx_err_t cx_sha512_init_no_throw(cx_sha512_t *hash) {
    return CX_OK;
}

cx_err_t cx_aes_init_key_no_throw(const uint8_t *rawkey, size_t key_len, cx_aes_key_t *key) {
    return CX_OK;
}

cx_err_t cx_hmac_update(cx_hmac_t *hmac, const uint8_t *in, size_t in_len) {
    return CX_OK;
}

cx_err_t cx_aes_enc_block(const cx_aes_key_t *key, const uint8_t *inblock, uint8_t *outblock) {
    return CX_OK;
}

cx_err_t cx_hmac_final(cx_hmac_t *ctx, uint8_t *out, size_t *out_len) {
    return CX_OK;
}

cx_err_t cx_aes_dec_block(const cx_aes_key_t *key, const uint8_t *inblock, uint8_t *outblock) {
    return CX_OK;
}

void cx_rng_no_throw(uint8_t *buffer, size_t len) {
}

void handleRunTests(uint8_t p1,
                    uint8_t p2,
                    uint8_t *wireBuffer,
                    size_t wireSize,
                    bool isNewCall) {
}

void os_perso_derive_node_bip32 ( cx_curve_t curve, const unsigned int * path, unsigned int pathLength, unsigned char * privateKey, unsigned char * chain ) {}

void ui_idle(void) {}

void io_seproxyhal_se_reset(void) {}

void io_seproxyhal_io_heartbeat(void) {}

void io_send_buf(uint16_t code, uint8_t* buffer, size_t bufferSize){}

void io_seproxyhal_init_ux(void) {}

typedef int bagl_element_t;
void io_seproxyhal_display(const bagl_element_t* element) {}

void io_seproxyhal_init_button(void) {}

unsigned int io_seph_is_status_sent ( void ) {
    return 1;
}

typedef enum {
    // We are doing IO, display handlers should not fire
    IO_EXPECT_IO = 42,  // Note: random constants
    // We are displaying things, IO handlers should not fire
    IO_EXPECT_UI = 47,
    // We should not be handling events
    IO_EXPECT_NONE = 49,
} io_state_t;

io_state_t io_state = IO_EXPECT_NONE;

bool device_is_unlocked() {
    return true;
}

void *pic(void *link_address) {
    return link_address;
}

typedef void timeout_callback_fn_t(bool ux_allowed);
void nanos_set_timer(int ms, timeout_callback_fn_t* cb) {
}

