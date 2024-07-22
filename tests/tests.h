//
// Created by Ruben on 2024-07-17.
//

#ifndef SCSD_LIB_TESTS_H
#define SCSD_LIB_TESTS_H

#define ASSERT_EQUAL(expected, actual) \
if ((expected) != (actual)) { \
    fprintf(stderr, "Assertion failed: expected %d, but got %d\n", (expected), (actual)); \
    return 1; \
} else { \
    printf("Test passed: %d == %d\n", (expected), (actual)); \
}

#endif //SCSD_LIB_TESTS_H
