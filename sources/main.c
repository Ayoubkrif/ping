#include <stdio.h>
#include <stdlib.h>

#include "ping.h"
#include <assert.h>
#include <string.h>

static int16
checksum
// (const icmp *)
(void *data, int len) {
    uint32_t sum = 0;
    uint16_t *ptr = data;
    
    // Sum all 16-bit words
    while (len > 1) {
        sum += *ptr++;
        len -= 2;
    }
    
    // Handle odd byte
    if (len == 1)
        sum += *(uint8_t *)ptr;
    
    // Fold 32-bit sum to 16 bits
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    
    return ~sum;  // One's complement
}

rawicmp
*MakeICMP
(int8 type, int8 code, int8 *data, int16 size) {
	int16 n;
	icmp *p;

	if (!data || !size)
		return (NULL);
	n = sizeof(icmp) + size;
	p = (icmp *)malloc($i n);
	assert(p);
	bzero(p, n);
	p->type = type;
	p->code = code;
	memcpy(&p->data, data, size);
	p->checksum = checksum(p);
	return (p);
}

int	main(int argc, char **argv)
{
	if (argc != 2) {
	   fprintf(stderr, "Usage: %s host port msg...\n", argv[0]);
	   exit(EXIT_FAILURE);
	}
	check_flags();
	printf("Hello world !\n");
// DONE: ouvrir une socket | socket
	int sock = open_raw_socket();
// TODO: resoudre le DNS | gethostbyname, getaddrinfo
	getaddrinfo();
// TODO: commencer a envoyer selon ICMP | sendto, recvfrom
// 		Quel payload ?
// 		Comment appeler sendto ? rcvfrom ?
// 			- faire une fonction qui envoie chaque morceau de send ?
// 			- recv et verifier que on a bien recu le bon truc?
	IMCP_send_echo_request(sock, argv[1]);
// TODO: interpreter et afficher les resultats | printf
	return (EXIT_SUCCESS);
}
