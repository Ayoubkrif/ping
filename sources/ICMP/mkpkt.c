#include "ping.h"

IcmpPacket*
ICMP_mkpkt
(int8 type, int8 code, int8 *data, int16 size) {
	if (!data || !size)
		return (NULL);
	IcmpPacket	*p;
	int			n;
	n = sizeof(int16) + sizeof(struct icmphdr) + size;
	p = (IcmpPacket*)malloc($i n);
	assert(p);
	bzero(p, n);
	p->size = size;
	p->header.type = type;
	p->header.code = code;
	memcpy(&p->data, data, size);
	p->header.checksum = ICMP_checksum(p, n);
	return (p);
}
