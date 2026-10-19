#include "ping.h"

int
main
(int argc, char **argv) {
	
	if (argc != 2) {
	   fprintf(stderr, "Usage: %s ...\n", argv[0]);
	   exit(EXIT_FAILURE);
	}

	// check if user can open raw sock
	check_flags();

	// DONE: ouvrir une socket | socket
	int sock = open_raw_socket();

	// DONE: Obtenir IP dest -> resoudre le DNS
	struct sockaddr_in	dest_addr;
	if (DNS_resolve(argv[1], &dest_addr) == false) {
	   fprintf(stderr, "cannot solve \"%s\"\n", argv[1]);
	   exit(EXIT_FAILURE);
	}
	char			ip_str[INET_ADDRSTRLEN];
	inet_ntop(AF_INET, &dest_addr.sin_addr, ip_str, sizeof(ip_str));
	printf("<%s> = <%s>\n", argv[1], ip_str);

// DONE: envoyer selon icmp
	IMCP_send_echo_request(sock, &dest_addr);
// TODO: recevoir le packet
// recvfrom dest_addr pour filtrer le bon pkt
	// ICMP_recv_echo_reply(sock, &dest_addr);
// TODO: interpreter et afficher les resultats | printf
	return (EXIT_SUCCESS);
}
