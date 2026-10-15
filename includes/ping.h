#pragma once

#include <sys/types.h>

// net
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/ip_icmp.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// std
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <errno.h>

typedef u_int8_t int8;
typedef u_int16_t int16;
typedef u_int32_t int32;
typedef u_int64_t int64;

#define $i (int)

void	check_flags(void);
int		open_raw_socket(void);
int		DNS_resolve(char *hostname, struct sockaddr_in *dest_addr);

typedef struct s_icmp {
	int16			size;
	struct icmphdr	header;
	int8			data[];
} IcmpPacket;

int16	ICMP_checksum(void *data, int len);
void	ICMP_print(IcmpPacket *pkt);
void	IMCP_send_echo_request(int sock, struct sockaddr_in *dest_addr);

IcmpPacket	*ICMP_mkpkt(int8, int8, int8*, int16);
