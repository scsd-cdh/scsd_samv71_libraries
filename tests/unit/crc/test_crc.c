//
// Created by Ruben on 2024-07-17.
//

#include "../../tests.h"
#include "test_crc.h"
#include "../../../lib/crc/crc.h"
#include <stdio.h>

bool test_crc_calculate_crc() {
    {
        uint8_t buffer[] = {0x00, 0x00, 0x00, 0x00};
        uint8_t expected_crc = 0x12;
        uint8_t crc_result = calculate_crc(buffer, sizeof(buffer));

        if (crc_result != expected_crc) {
            printf("Test failed: expected CRC %u, got %u\n", expected_crc, crc_result);
            return false;
        }

        if (!check_data_validity(buffer, sizeof(buffer), crc_result)) {
            printf("Test failed: expected CRC %u to be valid but it wasn't.\n", crc_result);
            return false;
        }
    }

    {
        uint8_t buffer[] = {0xF2, 0x01, 0x83};
        uint8_t expected_crc = 0xC2;
        uint8_t crc_result = calculate_crc(buffer, sizeof(buffer));

        if (crc_result != expected_crc) {
            printf("Test failed: expected CRC %u, got %u\n", expected_crc, crc_result);
            return false;
        }

        if (!check_data_validity(buffer, sizeof(buffer), crc_result)) {
            printf("Test failed: expected CRC %u to be valid but it wasn't.\n", crc_result);
            return false;
        }
    }

    {
        uint8_t buffer[] = {0x0F, 0xAA, 0x00, 0x55};
        uint8_t expected_crc = 0xC6;
        uint8_t crc_result = calculate_crc(buffer, sizeof(buffer));

        if (crc_result != expected_crc) {
            printf("Test failed: expected CRC %u, got %u\n", expected_crc, crc_result);
            return false;
        }

        if (!check_data_validity(buffer, sizeof(buffer), crc_result)) {
            printf("Test failed: expected CRC %u to be valid but it wasn't.\n", crc_result);
            return false;
        }
    }

    {
        uint8_t buffer[] = {0x00, 0xFF, 0x55, 0x11};
        uint8_t expected_crc = 0x77;
        uint8_t crc_result = calculate_crc(buffer, sizeof(buffer));

        if (crc_result != expected_crc) {
            printf("Test failed: expected CRC %u, got %u\n", expected_crc, crc_result);
            return false;
        }

        if (!check_data_validity(buffer, sizeof(buffer), crc_result)) {
            printf("Test failed: expected CRC %u to be valid but it wasn't.\n", crc_result);
            return false;
        }
    }

    {
        uint8_t buffer[] = {0x33, 0x22, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};
        uint8_t expected_crc = 0x11;
        uint8_t crc_result = calculate_crc(buffer, sizeof(buffer));

        if (crc_result != expected_crc) {
            printf("Test failed: expected CRC %u, got %u\n", expected_crc, crc_result);
            return false;
        }

        if (!check_data_validity(buffer, sizeof(buffer), crc_result)) {
            printf("Test failed: expected CRC %u to be valid but it wasn't.\n", crc_result);
            return false;
        }
    }

    {
        uint8_t buffer[] = {0x92, 0x6B, 0x55};
        uint8_t expected_crc = 0x33;
        uint8_t crc_result = calculate_crc(buffer, sizeof(buffer));

        if (crc_result != expected_crc) {
            printf("Test failed: expected CRC %u, got %u\n", expected_crc, crc_result);
            return false;
        }

        if (!check_data_validity(buffer, sizeof(buffer), crc_result)) {
            printf("Test failed: expected CRC %u to be valid but it wasn't.\n", crc_result);
            return false;
        }
    }

    {
        uint8_t buffer[] = {0xFF, 0xFF, 0xFF, 0xFF};
        uint8_t expected_crc = 0x6C;
        uint8_t crc_result = calculate_crc(buffer, sizeof(buffer));

        if (crc_result != expected_crc) {
            printf("Test failed: expected CRC %u, got %u\n", expected_crc, crc_result);
            return false;
        }

        if (!check_data_validity(buffer, sizeof(buffer), crc_result)) {
            printf("Test failed: expected CRC %u to be valid but it wasn't.\n", crc_result);
            return false;
        }
    }

    return true;
}

bool test_crc() {
    bool all_tests_passed = true;

    all_tests_passed &= test_crc_calculate_crc();

    return all_tests_passed;
}
