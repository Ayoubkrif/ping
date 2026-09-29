#include "ping.h"

// TODO: resoudre le DNS | gethostbyname, getaddrinfo
void
DNS_resolve
(int sock) {
	char *node;
	char *service = NULL; // port
	struct addrinfo hints;
	struct addrinfo *res;
	getaddrinfo(node, service, hints, &res);
}
