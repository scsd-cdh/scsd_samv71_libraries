//
// Created by Ruben on 2024-07-17.
//

#include "../../tests.h"
#include "test_tiny_stack_trace.h"
#include "../../../lib/tiny_stack_trace/tiny_stack_trace.h"
#include <stdio.h>

bool test_tst_throw_and_read_latest_error() {
    tst_throw(1001);
    tst_throw(1002);
    tst_throw(1003);

    uint16_t error;
    if (!tst_read_latest_error(&error) || error != 1003) {
        printf("Test failed: expected latest error 1003, got %u\n", error);

        return false;
    }

    return true;
}

bool test_tst_throw_and_pop_latest_error() {
    tst_throw(1001);
    tst_throw(1002);
    tst_throw(1003);

    uint16_t error;
    if (!tst_pop_latest_error(&error) || error != 1003) {
        printf("Test failed: expected latest error 1003, got %u\n", error);
        return false;
    }
    if (!tst_pop_latest_error(&error) || error != 1002) {
        printf("Test failed: expected latest error 1002, got %u\n", error);
        return false;
    }
    if (!tst_pop_latest_error(&error) || error != 1001) {
        printf("Test failed: expected latest error 1001, got %u\n", error);
        return false;
    }
    if (tst_pop_latest_error(&error)) {
        printf("Test failed: expected no errors left, but got %u\n", error);
        return false;
    }
    return true;
}

bool test_tst_throw_and_read_stack_trace() {
    uint16_t expected[TINY_STACK_TRACE_LENGTH] = {1001, 1002, 1003, 0, 0, 0, 0, 0, 0, 0};
    uint16_t actual[TINY_STACK_TRACE_LENGTH] = {0};

    tst_throw(1001);
    tst_throw(1002);
    tst_throw(1003);

    if (!tst_read_stack_trace(actual)) {
        printf("Test failed: expected to read stack trace\n");
        return false;
    }
    for (int i = 0; i < TINY_STACK_TRACE_LENGTH; i++) {
        if (expected[i] != actual[i]) {
            printf("Test failed: expected %u at position %d, got %u\n", expected[i], i, actual[i]);
            return false;
        }
    }
    return true;
}

bool test_tst_throw_and_pop_stack_trace() {
    uint16_t expected[TINY_STACK_TRACE_LENGTH] = {1001, 1002, 1003, 0, 0, 0, 0, 0, 0, 0};
    uint16_t actual[TINY_STACK_TRACE_LENGTH] = {0};

    tst_throw(1001);
    tst_throw(1002);
    tst_throw(1003);

    if (!tst_pop_stack_trace(actual)) {
        printf("Test failed: expected to pop stack trace\n");
        return false;
    }
    for (int i = 0; i < TINY_STACK_TRACE_LENGTH; i++) {
        if (expected[i] != actual[i]) {
            printf("Test failed: expected %u at position %d, got %u\n", expected[i], i, actual[i]);
            return false;
        }
    }
    if (!tst_is_empty()) {
        printf("Test failed: expected buffer to be empty\n");
        return false;
    }
    return true;
}

bool test_tiny_stack_trace() {
    bool all_tests_passed = true;

    all_tests_passed &= test_tst_throw_and_read_latest_error();
    tst_empty_stack();

    all_tests_passed &= test_tst_throw_and_pop_latest_error();
    tst_empty_stack();

    all_tests_passed &= test_tst_throw_and_read_stack_trace();
    tst_empty_stack();

    all_tests_passed &= test_tst_throw_and_pop_stack_trace();
    tst_empty_stack();

    return all_tests_passed;
}
