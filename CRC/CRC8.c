/*
* CRC8.c
 *
 * Created: 2024-07-13 2:17:34 PM
 *  Author: Rowan
*/

#include "CRC8.h"

/* Calculates CRC according to the specification */
uint8_t calculate_crc(uint8_t* buffer, uint8_t buffer_size) {

    uint8_t crc = crc_init_value;

    // For each byte of data
    for (int i = 0; i < buffer_size; i++) {
        //Check the table at index equal to (current_byte XOR current_crc)
        crc = crc_lookup_table[buffer[i] ^ crc];
    }

    /* Return the final CRC value XORed with the crc_xor_value */
    return crc ^ crc_xor_value;
}

/* Verifies data integrity by recalculating the CRC and comparing */
uint8_t check_data_validity(uint8_t* buffer, uint8_t buffer_size, uint8_t crc_result) {
    return calculate_crc(buffer, buffer_size) == crc_result;
}

/* Verifies data integrity using the magic check, where the buffer contains the data appended with the CRC */
uint8_t magic_check_data_validity(uint8_t* buffer_with_crc, uint8_t buffer_size) {

    // Calculate the CRC of the buffer XORed with the crc_xor_value (as seen in Example 7.2 of the specification)
    uint8_t checksum = calculate_crc(buffer_with_crc, buffer_size) ^ crc_xor_value;

    /* This result should be equal to crc_magic_check */
    return checksum == crc_magic_check;
}
