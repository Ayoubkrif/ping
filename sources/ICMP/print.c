#include "ping.h"

void	ICMP_print(datagram *to_print) {
	printf("size\t%d\ntype\t%d\ncode\t%d\ncheck\t%d\n"
			"data\t%.*s\n",
			to_print->sizeOfPl,to_print->pkt->hdr.type, to_print->pkt->hdr.code, to_print->pkt->hdr.checksum,
			to_print->sizeOfPl, to_print->pkt->pl);
}
