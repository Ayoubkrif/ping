#include "ping.h"

void	ICMP_print(IcmpPacket *pkt) {
	printf("size\t%d\ntype\t%d\ncode\t%d\ncheck\t%d\n"
			"data\t%.*s\n",
			pkt->size,pkt->header.type, pkt->header.code, pkt->header.checksum,
			pkt->size, pkt->data);
}
