#ifndef SCSD_LIB_TINY_STACK_TRACE_H
#define SCSD_LIB_TINY_STACK_TRACE_H

#ifndef TINY_STACK_TRACE_LENGTH
#define TINY_STACK_TRACE_LENGTH 10
#endif

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint16_t buffer[TINY_STACK_TRACE_LENGTH];
    uint8_t head;
    uint8_t count;
} tst_circular_buffer_t;

void tst_throw(uint16_t error);
bool tst_pop_latest_error(uint16_t *error);
bool tst_read_latest_error(uint16_t *error);
bool tst_pop_stack_trace(uint16_t buffer[TINY_STACK_TRACE_LENGTH]);
bool tst_read_stack_trace(uint16_t buffer[TINY_STACK_TRACE_LENGTH]);
void tst_empty_stack();
bool tst_is_empty();

#endif //SCSD_LIB_TINY_STACK_TRACE_H
