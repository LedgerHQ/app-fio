#ifndef H_FIO_APP_SIGN_COIUNTED_SECTION
#define H_FIO_APP_SIGN_COIUNTED_SECTION

#include <stdint.h>
#include <stdbool.h>
#include "utils.h"

#define MAX_NESTED_COUNTED_SECTIONS 5

// currencLevel=1 strores value on count[0], etc...
typedef struct {
    uint32_t initialized_magic;
    uint32_t count[MAX_NESTED_COUNTED_SECTIONS];
    uint8_t currentLevel;
} tx_counted_section_t;

__noinline_due_to_stack__ void countedSectionInit(tx_counted_section_t *cs);

__noinline_due_to_stack__ bool countedSectionBegin(tx_counted_section_t *cs,
                                                   uint32_t expectedLength);

__noinline_due_to_stack__ bool countedSectionProcess(tx_counted_section_t *cs,
                                                     uint32_t expectedLength);

__noinline_due_to_stack__ bool countedSectionEnd(tx_counted_section_t *cs);

__noinline_due_to_stack__ bool countedSectionFinalize(tx_counted_section_t *cs);

#ifdef DEVEL
__noinline_due_to_stack__ void run_countedSection_test();
#endif  // DEVEL

#endif  // H_FIO_APP_SIGN_COIUNTED_SECTION
