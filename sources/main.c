#include "ping.h"

// guideline:
// 	initialiser la sequence
// 	set le signal pour arreter la sequence
// 	lancer la sequence
// 	imprime a chaque reception
// 	sequence fini sur fin ou signal
//
//
// guideline pour la boucle ping
	//init timestamp next envoi de paquet = temps acutel
	//tant que pas d'interruption et que compteur pas vide
        // Si temp actuel - temps vers next paquet ecoule
			// envoie le next paquet
			// set a temps actuel + interval
        // Attente d'un paquet ou de la fin du timer
		// SI paquet receptionne
			// imprime les metriques du paquet
			// enregistre pour le recap

struct s_opt g_opt = {-1, 1, 64, false};
bool		g_stop = false;

void	handle_int(int signum) {
	(void) signum;
	g_stop = true;
}

void	set_sig_handler(void)
{
	struct sigaction	sig_int;

	sig_int.sa_handler = handle_int;
	sig_int.sa_flags = 0;
	sigemptyset(&sig_int.sa_mask);
	sigaction(SIGINT, &sig_int, 0);
}

int
main
(int argc, char **argv) {
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

	set_sig_handler();

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
