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

// Que manque-t-il ?
// recuperer les metriques pour les imprimer et les enregister
//
void	ping_loop(int sock, struct sockaddr_in *dest_addr) {
	struct timespec now, nxt, interval = {0,0};
	
	timespec_add_double(&interval, g_opt.interval);
	
	//init timestamp next envoi de paquet = temps acutel
	clock_gettime(CLOCK_MONOTONIC, &nxt);

	int	packet_rcvd = 0;
	//tant que pas d'interruption et que compteur pas vide
	while (!g_stop && (g_opt.count == (int32)(-1) || g_opt.count - packet_rcvd)) {
		clock_gettime(CLOCK_MONOTONIC, &now);
        // Si temp actuel - temps vers next paquet ecoule
		if (timediff(now, nxt) < 0) {
			// envoie le next paquet
			IMCP_send_echo_request(sock, dest_addr);
			// set a temps actuel + interval
			timespec_add(&nxt, &now, &interval);
		}
        // Attente d'un paquet ou de la fin du timer
		ICMP_recv_echo_reply(sock, dest_addr);
		// SI paquet receptionne
			// imprime les metriques du paquet
			// enregistre pour le recap
	}
}

