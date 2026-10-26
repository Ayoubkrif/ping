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
#include <time.h>

typedef u_int8_t int8;
typedef u_int16_t int16;
typedef u_int32_t int32;
typedef u_int64_t int64;

#define $i (int)

void	check_flags(void);
int		open_raw_socket(void);
int16	checksum(void *, int);
int		DNS_resolve(char *hostname, struct sockaddr_in *dest_addr);


typedef struct __attribute__((packed)) s_icmp {
	struct icmphdr	hdr;
	int8			pl[];
} IcmpPacket;

typedef struct datagram {
	int16			sizeOfPl;
	IcmpPacket		*pkt;
} datagram;

void	ICMP_print(datagram *);
void	IMCP_send_echo_request(int sock, struct sockaddr_in *dest_addr);
void	ICMP_recv_echo_reply(int sock, struct sockaddr_in *dest_addr);
IcmpPacket	*ICMP_mkpkt(int8, int8, int8*, int16);


typedef struct s_metrics {
	double	avg;
	double	stddev;
	double	min;
	double	max;
	struct	{
		double	*rtt_ms;
		int32	size;
	} record;
} metrics;

typedef struct s_opt {
	int32	count;
	int32	timeOut;
	int32	ttl;
} opt;

extern struct opt flags;
extern struct timespec start, end;
