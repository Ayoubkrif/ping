#include "ping.h"

static int16
checksum
(void *data, int len) {
    int32 sum = 0;
    int16 *ptr = data;

    // Sum all 16-bit words
    while (len > 1) {
        sum += *ptr++;
        len -= 2;
    }
    // Handle odd byte
    if (len == 1)
        sum += *(uint8_t *)ptr;

    // Fold 32-bit sum to 16 bits
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);

    return ~sum;  // One's complement
}

