#include "ping.h"

IcmpPacket*
ICMP_mkpkt
(int8 type, int8 code, int8 *data, int16 sizeOfPl) {
	if (!data || !sizeOfPl)
		return (NULL);
	IcmpPacket	*pkt;
	int			totalSize;
	totalSize = sizeof(struct icmphdr) + sizeOfPl;
	pkt = (IcmpPacket*)malloc($i totalSize);
	assert(pkt);
	bzero(pkt, totalSize);
	pkt->hdr.type = type;
	pkt->hdr.code = code;
	memcpy(&pkt->pl, data, sizeOfPl);
	pkt->hdr.checksum = ICMP_checksum(pkt, totalSize);
	return (pkt);
}
