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

typedef u_int8_t int8;
typedef u_int16_t int16;
typedef u_int32_t int32;
typedef u_int64_t int64;

#define $i (int)

void	check_flags(void);
int		open_raw_socket(void);
int		DNS_resolve (char *hostname, struct in_addr *dest_ip);

int16	ICMP_checksum(void *data, int len);
void	IMCP_send_echo_request(int sock, char *dest, struct in_addr dest_ip);

// struct icmphdr
// {
//   uint8_t type;		/* message type */
//   uint8_t code;		/* type sub-code */
//   uint16_t checksum;
//   union
//   {
//     struct
//     {
//       uint16_t	id;
//       uint16_t	sequence;
//     } echo;			/* echo datagram */
//     uint32_t	gateway;	/* gateway address */
//     struct
//     {
//       uint16_t	__glibc_reserved;
//       uint16_t	mtu;
//     } frag;			/* path mtu discovery */
//   } un;
// };

typedef struct s_icmp {
	struct icmphdr	header;
	int8			data[];
} IcmpPacket;

IcmpPacket	*MakeICMP(int8, int8, int8*, int16);
