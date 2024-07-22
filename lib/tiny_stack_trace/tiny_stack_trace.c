#include "tiny_stack_trace.h"

static volatile tst_circular_buffer_t circular_buffer = {
    .buffer = {0},
    .head = 0,
    .count = 0
};

void tst_throw(uint16_t error) {
    circular_buffer.buffer[circular_buffer.head] = error;
    circular_buffer.head = (circular_buffer.head + 1) % TINY_STACK_TRACE_LENGTH;
    if (circular_buffer.count < TINY_STACK_TRACE_LENGTH) {
        circular_buffer.count ++;
    }
}

bool tst_pop_latest_error(uint16_t* error) {
    if (circular_buffer.count == 0) {
        return false;
    }

    int latestIndex = (circular_buffer.head - 1 + TINY_STACK_TRACE_LENGTH) % TINY_STACK_TRACE_LENGTH;
    *error = circular_buffer.buffer[latestIndex];

    circular_buffer.count--;
    circular_buffer.head = latestIndex;

    return true;
}

bool tst_read_latest_error(uint16_t* error) {
    if (circular_buffer.count == 0) {
        return false;
    }

    int latestIndex = (circular_buffer.head - 1 + TINY_STACK_TRACE_LENGTH) % TINY_STACK_TRACE_LENGTH;
    *error = circular_buffer.buffer[latestIndex];
    return true;
}

bool tst_pop_stack_trace(uint16_t buffer[TINY_STACK_TRACE_LENGTH]) {
    if (circular_buffer.count == 0) {
        return false;
    }

    int currentIndex = circular_buffer.head;
    for (int i = 0; i < circular_buffer.count; i++) {
        currentIndex = (currentIndex - 1 + TINY_STACK_TRACE_LENGTH) % TINY_STACK_TRACE_LENGTH;
        buffer[circular_buffer.count - 1 - i] = circular_buffer.buffer[currentIndex];
    }

    circular_buffer.count = 0;
    circular_buffer.head = 0;

    return true;
}

bool tst_read_stack_trace(uint16_t buffer[TINY_STACK_TRACE_LENGTH]) {
    if (circular_buffer.count == 0) {
        return false;
    }

    int currentIndex = circular_buffer.head;
    for (int i = 0; i < circular_buffer.count; i++) {
        currentIndex = (currentIndex - 1 + TINY_STACK_TRACE_LENGTH) % TINY_STACK_TRACE_LENGTH;
        buffer[circular_buffer.count - 1 - i] = circular_buffer.buffer[currentIndex];
    }

    return true;
}

void tst_empty_stack() {
    circular_buffer.count = 0;
    circular_buffer.head = 0;
}

bool tst_is_empty() {
    return circular_buffer.count == 0;
}
