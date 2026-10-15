#include "ping.h"

static int8 echo[] = "test";

// ssize_t
// sendto
// (int sockfd, const void buf[.size], size_t size,
// 	int flags, const struct sockaddr *dest_addr, socklen_t addrlen);
void	IMCP_send_echo_request(int sock, struct sockaddr_in *dest_addr) {
	IcmpPacket	*to_send = ICMP_mkpkt(ICMP_ECHO, 0, echo, sizeof(echo));
	printf("pkt to send:\n");
	ICMP_print(to_send);
	sendto(sock, (int8*)to_send + sizeof(int16), to_send->size + sizeof(struct icmphdr),
			0, (struct sockaddr *)dest_addr, sizeof(struct sockaddr_in));
}
