#include "ping.h"

// TODO: resoudre le DNS | gethostbyname, getaddrinfo
int
DNS_resolve
(char *hostname, struct in_addr *dest_ip) {
	char *node = hostname;
	char *service = NULL; // port
	struct addrinfo *res = NULL;
	struct addrinfo hints;
	bzero(&hints, sizeof(struct addrinfo));
	hints.ai_flags		= 0;
	hints.ai_family 	= AF_INET; //ipv4
	hints.ai_protocol	= IPPROTO_ICMP;
	hints.ai_socktype	= SOCK_RAW;
	int errcode = getaddrinfo(node, service, &hints, &res);
	if (errcode) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errcode));
		return (false);
	}
	/* getaddrinfo() returns a list of address structures.
	 * the first one that match can be used 
	 * */
	// no need to check if (res == NULL), getaddrinfo would returned an error
	//
	*dest_ip = ((struct sockaddr_in *)res->ai_addr)->sin_addr;
	freeaddrinfo(res);           /* For leaks */
	return (true);
}
