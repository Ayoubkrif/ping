#pragma once

#include <sys/types.h>

#include <sys/socket.h>
#include <netdb.h>
#include <netinet/ip_icmp.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef u_int8_t int8;
typedef u_int16_t int16;
typedef u_int32_t int32;
typedef u_int64_t int64;

#define $i (int)

void	check_flags(void);
int		DNS_resolve (char *hostname, struct in_addr *dest_ip);
int		open_raw_socket(void);
void	IMCP_send_echo_request(int sock, char *dest, struct in_addr dest_ip);


// typedef struct s_rawicmp {
// 	int8	type;
// 	int8	code;
// 	int16	checksum;
// 	int8	data[];
// } rawicmp;
//
// typedef struct s_icmp {
// 	int8	type;
// 	int8	code;
// 	int8	*data;
// } icmp;

struct icmphdr *MakeICMP(int8, int8, int8*, int16);
