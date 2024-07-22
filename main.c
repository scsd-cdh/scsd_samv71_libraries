#include "tests/unit/crc/test_crc.h"
#include "tests/unit/tiny_stack_trace/test_tiny_stack_trace.h"
#include <stdio.h>

int main(void) {
    if(test_crc()) {
        printf("CRC tests passed.\n");
    } else {
        printf("CRC tests failed.\n");
    }

    if(test_tiny_stack_trace()) {
        printf("Tiny Stack Trace tests passed.\n");
    } else {
        printf("Tiny Stack Trace tests failed.\n");
    }

    return 0;
}
