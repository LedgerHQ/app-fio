#ifdef DEVEL

#include "signTransactionCountedSection.h"
#include "assert.h"

static void tooMuchNesting_test() {
    tx_counted_section_t cs;
    countedSectionInit(&cs);
    ASSERT(countedSectionBegin(&cs, 1000));
    ASSERT(countedSectionBegin(&cs, 1000));
    ASSERT(countedSectionBegin(&cs, 1000));
    ASSERT(countedSectionBegin(&cs, 1000));
    ASSERT(countedSectionBegin(&cs, 1000));
    ASSERT(!countedSectionBegin(&cs, 1000));
}

static void finalizeOnNonZeroLevel_test() {
    tx_counted_section_t cs;
    countedSectionInit(&cs);
    ASSERT(countedSectionBegin(&cs, 0));
    ASSERT(!countedSectionFinalize(&cs));
}

static void endSectionOnZeroLevel_test() {
    tx_counted_section_t cs;
    countedSectionInit(&cs);
    ASSERT(!countedSectionEnd(&cs));
}

static void underflowLevel0_test() {
    tx_counted_section_t cs;
    countedSectionInit(&cs);
    ASSERT(countedSectionBegin(&cs, 1000));
    ASSERT(countedSectionProcess(&cs, 999));
    ASSERT(!countedSectionEnd(&cs));
}

static void overflowLevel0_test() {
    tx_counted_section_t cs;
    countedSectionInit(&cs);
    ASSERT(countedSectionBegin(&cs, 1000));
    ASSERT(countedSectionProcess(&cs, 1000));
    ASSERT(!countedSectionProcess(&cs, 1));
}

static void overflowLevel0From2_test() {
    tx_counted_section_t cs;
    countedSectionInit(&cs);
    ASSERT(countedSectionBegin(&cs, 1000));
    ASSERT(countedSectionProcess(&cs, 300));
    ASSERT(countedSectionBegin(&cs, 800));
    ASSERT(countedSectionProcess(&cs, 500));
    ASSERT(countedSectionBegin(&cs, 500));
    ASSERT(!countedSectionProcess(&cs, 250));
}

static void underflowLevel0From2_test() {
    tx_counted_section_t cs;
    countedSectionInit(&cs);
    ASSERT(countedSectionBegin(&cs, 1000));
    ASSERT(countedSectionProcess(&cs, 100));
    ASSERT(countedSectionBegin(&cs, 800));
    ASSERT(countedSectionProcess(&cs, 300));
    ASSERT(countedSectionBegin(&cs, 500));
    ASSERT(countedSectionProcess(&cs, 250));
    ASSERT(countedSectionProcess(&cs, 250));
    ASSERT(countedSectionEnd(&cs));
    ASSERT(countedSectionEnd(&cs));
    ASSERT(!countedSectionEnd(&cs));
}

static void correct_test() {
    tx_counted_section_t cs;
    countedSectionInit(&cs);
    ASSERT(countedSectionBegin(&cs, 1000));
    ASSERT(countedSectionProcess(&cs, 200));
    ASSERT(countedSectionBegin(&cs, 800));
    ASSERT(countedSectionProcess(&cs, 300));
    ASSERT(countedSectionBegin(&cs, 500));
    ASSERT(countedSectionProcess(&cs, 250));
    ASSERT(countedSectionProcess(&cs, 250));
    ASSERT(countedSectionEnd(&cs));
    ASSERT(countedSectionEnd(&cs));
    ASSERT(countedSectionEnd(&cs));
}

__noinline_due_to_stack__ void run_countedSection_test() {
    tooMuchNesting_test();
    finalizeOnNonZeroLevel_test();
    endSectionOnZeroLevel_test();
    underflowLevel0_test();
    overflowLevel0_test();
    overflowLevel0From2_test();
    underflowLevel0From2_test();
    correct_test();
}

#endif