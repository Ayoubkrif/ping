#pragma once
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/ip_icmp.h>
#include <netinet/ip.h>
#include <unistd.h>

typedef u_int8_t int8;
typedef u_int16_t int16;
typedef u_int32_t int32;
typedef u_int64_t int64;

#define $i (int)

void	check_flags(void);
void	DNS_resolve (int sock);
int		open_raw_socket(void);
void	IMCP_send_echo_request(int sock, char *dest);


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
