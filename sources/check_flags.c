#include <sys/capability.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

void
check_flags
(void) {
	cap_flag_value_t	value;
	cap_t caps = cap_get_proc();
	if (caps == NULL) {
		fprintf(stderr, "cap_get_proc:<%s> \n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	if (cap_get_flag(caps, CAP_NET_RAW, CAP_EFFECTIVE, &value) == -1) {
		fprintf(stderr, "cap_get_flag:<%s> \n", strerror(errno));
		cap_free(caps);
		exit(EXIT_FAILURE);
	}
	cap_free(caps);
	if (value == CAP_CLEAR) {
		fprintf(stderr, "User cannot open raw socket\n");
		exit(EXIT_FAILURE);
	}
}
