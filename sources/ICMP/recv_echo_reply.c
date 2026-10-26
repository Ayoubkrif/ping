// // Source - https://stackoverflow.com/q/58572989
// // Posted by newprogrammer
// // Retrieved 2026-09-27, License - CC BY-SA 4.0
#include "ping.h"
// ssize_t
// recvfrom
// (int sockfd, void buf[restrict .size], size_t size,
// 				int flags,
// 				struct sockaddr *_Nullable restrict src_addr, socklen_t *_Nullable restrict addrlen)

struct timespec end;
void
ICMP_recv_echo_reply
(int sock, struct sockaddr_in *dest_addr) {
	char buff[1460];
	struct iphdr *ip;
	ip = (struct iphdr *)buff;

	socklen_t addr_len = sizeof(struct sockaddr_in);
	ssize_t ipPktLen = recvfrom(sock, buff, sizeof(buff),
		0,
		(struct sockaddr *)dest_addr, &addr_len);
	clock_gettime(CLOCK_MONOTONIC, &end);

    // 1. Vérification d'erreur système sur recvfrom ou paquet trop court
	if (ipPktLen < 0) {
		perror("Erreur fatale lors de la réception (recvfrom)");
		exit(1);
    }
    if (ipPktLen < 20) {
		fprintf(stderr, "Erreur : Paquet reçu trop court (%zd octets, minimum requis : 20 octets pour l'en-tête IP).\n", ipPktLen);
		exit(1);
    }

	int8 ipHdrLen = 4 * ip->ihl;

    // 2. Vérification du checksum de l'en-tête IP
	if (checksum(ip, ipHdrLen)) {
        fprintf(stderr, "Erreur : Checksum de l'en-tête IPv4 invalide (paquet corrompu).\n");
		exit(1);
	}

	datagram	icmp_pkt;
	// Payload_IPv4_Size = ipPktLen − (ipHdrlen)
	// Payload_ICMP_Size = ipPktLen − (ipHdrlen) - icmphdrsize
	icmp_pkt.sizeOfPl = ipPktLen - ipHdrLen - sizeof(struct icmphdr);
	icmp_pkt.pkt = (IcmpPacket *)(buff + ipHdrLen);
	printf("packet recv:\n");
	ICMP_print(&icmp_pkt);
    // 3. Vérification du checksum du paquet ICMP
	if (checksum(icmp_pkt.pkt, icmp_pkt.sizeOfPl + sizeof(struct icmphdr))) {
		fprintf(stderr, "Erreur : Checksum ICMP invalide (données corrompues).\n");
		exit(1);
	}
}
