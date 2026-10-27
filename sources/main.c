#include "ping.h"

struct s_opt opt;

// guideline:
// 	remplir les options et argument
// 		Si plusieurs arguments alors fonctionne mais dit que ca traite pas les arguments qui viennent apres
// 		=>SCOPE 1 argument , skippe les flags pas compris
// 	initialiser la sequence
// 	set le signal pour arreter la sequence
// 	lancer la sequence
// 	imprime a chaque reception
// 	sequence fini sur fin ou signal


int
main
(int argc, char **argv) {

	opt.count = -1;
	opt.interval = 1;
	opt.ttl = 64;
	opt.verbose = false;
//TODO: getopt et remplir les opt
	parse_arguments(argc, argv);
	printf("c:\t%i\nttl:\t%i\ni:\t%f\nv:\t%s\n",opt.count, opt.ttl , opt.interval , opt.verbose ? "true" : "false");

	// check if user can open raw sock
	check_flags();

	// DONE: ouvrir une socket | socket
	int sock = open_raw_socket();

	// DONE: Obtenir IP dest -> resoudre le DNS
	struct sockaddr_in	dest_addr;
	if (DNS_resolve(argv[optind], &dest_addr) == false) {
	   fprintf(stderr, "cannot solve \"%s\"\n", argv[1]);
	   exit(EXIT_FAILURE);
	}
	char			ip_str[INET_ADDRSTRLEN];
	inet_ntop(AF_INET, &dest_addr.sin_addr, ip_str, sizeof(ip_str));
	printf("<%s> = <%s>\n", argv[1], ip_str);

// DONE: envoyer selon icmp
	IMCP_send_echo_request(sock, &dest_addr);

// DONE: recevoir le packet
// recvfrom dest_addr pour filtrer le bon pkt
	ICMP_recv_echo_reply(sock, &dest_addr);

// TODO: interpreter et afficher les resultats | printf
	double rtt_ms = (end.tv_sec - start.tv_sec) * 1000.0 +
		(end.tv_nsec - start.tv_nsec) / 1000000.0;
	printf("time=%.2f ms\n", rtt_ms);
	return (EXIT_SUCCESS);
}
