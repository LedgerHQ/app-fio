#include "signTransactionCountedSection.h"
#include "utils.h"

enum {
    TX_COUNTED_SECTION_INITIALIZED_MAGIC = 12345,
};

__noinline_due_to_stack__ void countedSectionInit(tx_counted_section_t *cs) {
    explicit_bzero(cs, SIZEOF(*cs));
    cs->initialized_magic = TX_COUNTED_SECTION_INITIALIZED_MAGIC;
}

__noinline_due_to_stack__ bool countedSectionBegin(tx_counted_section_t *cs,
                                                   uint32_t expectedLength) {
    STATIC_ASSERT(ARRAY_LEN(cs->count) == MAX_NESTED_COUNTED_SECTIONS,
                  "Incorrect tx_counted_section_t count length");
    ASSERT(cs->initialized_magic == TX_COUNTED_SECTION_INITIALIZED_MAGIC);

    // too deep nesting
    if (cs->currentLevel >= MAX_NESTED_COUNTED_SECTIONS) {
        return false;
    }

    cs->currentLevel++;
    cs->count[cs->currentLevel - 1] = expectedLength;
    return true;
}

__noinline_due_to_stack__ bool countedSectionProcess(tx_counted_section_t *cs,
                                                     uint32_t expectedLength) {
    STATIC_ASSERT(ARRAY_LEN(cs->count) == MAX_NESTED_COUNTED_SECTIONS,
                  "Incorrect tx_counted_section_t count length");
    ASSERT(cs->initialized_magic == TX_COUNTED_SECTION_INITIALIZED_MAGIC);
    ASSERT(cs->currentLevel <= MAX_NESTED_COUNTED_SECTIONS);

    for (size_t i = 0; i < cs->currentLevel; i++) {
        TRACE("Counted section %d/%d: We have %d, use %d.",
              (int) (i + 1),
              (int) cs->currentLevel,
              (int) cs->count[i],
              (int) expectedLength);
        if (cs->count[i] < expectedLength) {
            return false;
        }
        cs->count[i] -= expectedLength;
    }
    return true;
}

__noinline_due_to_stack__ bool countedSectionEnd(tx_counted_section_t *cs) {
    STATIC_ASSERT(ARRAY_LEN(cs->count) == MAX_NESTED_COUNTED_SECTIONS,
                  "Incorrect tx_counted_section_t count length");
    ASSERT(cs->initialized_magic == TX_COUNTED_SECTION_INITIALIZED_MAGIC);
    ASSERT(cs->currentLevel <= MAX_NESTED_COUNTED_SECTIONS);

    // curentLevel == 0 we cannot exit counted section
    if (cs->currentLevel == 0) {
        return false;
    }

    // Counted section mismatch
    if (cs->count[cs->currentLevel - 1] != 0) {
        return false;
    }

    cs->currentLevel--;
    return true;
}

__noinline_due_to_stack__ bool countedSectionFinalize(tx_counted_section_t *cs) {
    STATIC_ASSERT(ARRAY_LEN(cs->count) == MAX_NESTED_COUNTED_SECTIONS,
                  "Incorrect tx_counted_section_t count length");
    ASSERT(cs->initialized_magic == TX_COUNTED_SECTION_INITIALIZED_MAGIC);

    return (cs->currentLevel == 0);
}
