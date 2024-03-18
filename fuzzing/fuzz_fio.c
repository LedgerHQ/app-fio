#include "handlers.h"
#include "state.h"

#include <stdint.h>

#include <stdio.h>

static const int INS_NONE = -1;

typedef struct {
    uint8_t cla;
    uint8_t ins;
    uint8_t p1;
    uint8_t p2;
    uint8_t lc; //will be ignored    
} header_t;

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    // The size of the data should exceed the length of the header
    if (Size >= sizeof(header_t)){
        header_t * header = (header_t *) Data;
        uint8_t* data = (uint8_t *)(Data + sizeof(*header));
        size_t data_size = Size - sizeof(*header);
        
        printf("%hhx, %hhx, %hhx, %hhx\n", header->cla, header->ins, header->p1, header->p2);
        
        BEGIN_TRY {
            TRY {
                handler_fn_t* handlerFn = lookupHandler(header->ins);

                VALIDATE(handlerFn != NULL, ERR_UNKNOWN_INS);
                printf("Hander found\n");

                explicit_bzero(&instructionState, SIZEOF(instructionState));
                currentInstruction = header->ins;

                printf("Running handler\n");
                handlerFn(header->p1, header->p2, data, data_size, true);
            }
            CATCH_OTHER(e) {
            }
            FINALLY {
            }
        END_TRY;
        }
    }
    
    return 0;
}
