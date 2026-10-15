#include "ping.h"

int16
ICMP_checksum
(void *data, int len) {
	data += sizeof(int16);
	int32 sum = 0;
	int16 *ptr = data;

	// Sum all 16-bit words
	while (len > 1) {
		sum += *ptr++;
		len -= 2;
	}
	// Handle odd Byte
	if (len == 1)
		sum += *(uint8_t *)ptr;

	// sum carry with 16 lower
	sum = (sum >> 16) + (sum & 0xFFFF);
	// re-sum in case of sum is still overlapping
	sum += (sum >> 16);

	// One's complement
    return ~sum;
}
