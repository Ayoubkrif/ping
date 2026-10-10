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
	struct in_addr	dest_ip;
	if (DNS_resolve(argv[1], &dest_ip) == false) {
	   fprintf(stderr, "cannot solve \"%s\"\n", argv[1]);
	   exit(EXIT_FAILURE);
	}
	char			ip_str[INET_ADDRSTRLEN];
	inet_ntop(AF_INET, &dest_ip, ip_str, sizeof(ip_str));
	printf("<%s> = <%s>\n", argv[1], ip_str);

// TODO: commencer a envoyer selon ICMP | sendto, recvfrom
// 		Quel payload ?
// 		Comment appeler sendto ? rcvfrom ?
// 			- faire une fonction qui envoie chaque morceau de send ?
// 			- recv et verifier que on a bien recu le bon truc?
	IMCP_send_echo_request(sock, argv[1], dest_ip);
// TODO: interpreter et afficher les resultats | printf
	return (EXIT_SUCCESS);
}
