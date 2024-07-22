/*
 * crc.c
 *
 * Created: 2024-07-13 2:17:34 PM
 *  Author: Rowan
*/

#include "crc.h"

/* Calculates CRC according to the specification */
uint8_t calculate_crc(const uint8_t* buffer, uint8_t buffer_size) {

    uint8_t crc = crc_init_value;

    // For each byte of data
    for (int i = 0; i < buffer_size; i++) {
        //Check the table at index equal to (current_byte XOR current_crc)
        crc = crc_lookup_table[buffer[i] ^ crc];
    }

    /* Return the final CRC value XORed with the crc_xor_value */
    return crc ^ crc_xor_value;
}

/* Verifies data integrity using the magic check */
uint8_t check_data_validity(const uint8_t* buffer, uint8_t buffer_size, uint8_t crc_result) {
    uint8_t checksum = calculate_crc(buffer, buffer_size);
    return checksum == crc_result;
}
