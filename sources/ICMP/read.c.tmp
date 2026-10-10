// Source - https://stackoverflow.com/q/58572989
// Posted by newprogrammer
// Retrieved 2026-09-27, License - CC BY-SA 4.0
#include <ping.h>

int
ICMP_read
(int *sock) {
	char buff[1024];
	struct iphdr *ip;
	struct icmphdr *icmp;
	ip = (struct iphdr *)buff;
	icmp = (struct icmphdr *) (buff + sizeof(struct iphdr));

	if(read(*sock, buff, sizeof(buff)) > 0) {
		if(icmp->type == 0 && icmp->code == 0) return 1;
		else return -1;
	}
	return 0;
}
