#include "ping.h"

// TODO: resoudre le DNS | gethostbyname, getaddrinfo
int
DNS_resolve
(int sock, char *hostname) {
	char *node = hostname;
	char *service = NULL; // port
	struct addrinfo *res = NULL;
	struct addrinfo hints;
	bzero(&hints, sizeof(struct addrinfo));
	hints.ai_flags		= 0;
	hints.ai_family 	= AF_UNSPEC;
	hints.ai_protocol	= IPPROTO_RAW;
	hints.ai_socktype	= SOCK_RAW;
	return (getaddrinfo(node, service, &hints, &res) == -1);
}
