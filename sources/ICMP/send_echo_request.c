#include "ping.h"

// ssize_t
// sendto
// (int sockfd, const void buf[.size], size_t size,
// 	int flags, const struct sockaddr *dest_addr, socklen_t addrlen);
void	IMCP_send_echo_request(int sock, struct sockaddr_in *dest_addr) {
	datagram	DataGram;
	static int8 echo[] = "test";
	DataGram.sizeOfPl = sizeof(echo);
	DataGram.pkt = ICMP_mkpkt(ICMP_ECHO, 0, echo, DataGram.sizeOfPl);
	printf("pkt to send:\n");
	ICMP_print(&DataGram);
	// Send header + payload to dest_addr
	sendto(sock, (int8*)DataGram.pkt, DataGram.sizeOfPl + sizeof(struct icmphdr),
			0, (struct sockaddr *)dest_addr, sizeof(struct sockaddr_in));
	free(DataGram.pkt);
}
