#include "ping.h"

rawicmp
*MakeICMP
(int8 type, int8 code, int8 *data, int16 size) {
	int16 n;
	icmp *p;

	if (!data || !size)
		return (NULL);
	n = sizeof(icmp) + size;
	p = (icmp *)malloc($i n);
	assert(p);
	bzero(p, n);
	p->type = type;
	p->code = code;
	memcpy(&p->data, data, size);
	p->checksum = checksum(p);
	return (p);
}

