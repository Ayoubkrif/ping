#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
int	open_raw_socket(void) {
	int raw_socket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (raw_socket == -1) {
		fprintf(stderr, "socket:<%s> \n", strerror(errno));
		exit(EXIT_FAILURE);
	}
}
