#include "ping.h"

int	main(int argc, char **argv)
{
	if (argc != 2) {
	   fprintf(stderr, "Usage: %s ...\n", argv[0]);
	   exit(EXIT_FAILURE);
	}
	check_flags();
	printf("Hello world !\n");
// DONE: ouvrir une socket | socket
	int sock = open_raw_socket();
// TODO: resoudre le DNS | gethostbyname, getaddrinfo
	if (DNS_resolve(sock, argv[1]) == -1) {
	   fprintf(stderr, "cannot solve \"%s\"\n", argv[1]);
	   exit(EXIT_FAILURE);
	}

// TODO: commencer a envoyer selon ICMP | sendto, recvfrom
// 		Quel payload ?
// 		Comment appeler sendto ? rcvfrom ?
// 			- faire une fonction qui envoie chaque morceau de send ?
// 			- recv et verifier que on a bien recu le bon truc?
	IMCP_send_echo_request(sock, argv[1]);
// TODO: interpreter et afficher les resultats | printf
	return (EXIT_SUCCESS);
}
