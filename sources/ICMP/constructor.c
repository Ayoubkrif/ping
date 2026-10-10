#include "ping.h"

IcmpPacket*
MakeICMP
(int8 type, int8 code, int8 *data, int16 size) {
	if (!data || !size)
		return (NULL);
	IcmpPacket	*p;
	int			n;
	n = sizeof(IcmpPacket) + size;
	p = (IcmpPacket*)malloc($i n);
	assert(p);
	bzero(p, n);
	p->header.type = type;
	p->header.code = code;
	memcpy(&p->data, data, size);
	p->header.checksum = ICMP_checksum(p, n);
	return (p);
}

