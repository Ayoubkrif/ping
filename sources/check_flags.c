#include <sys/capability.h>
#include "ping.h"

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

void parse_arguments(int argc, char **argv) {
	int flag;
	// Tableau des options longues
	static struct option long_options[] = {
		{"verbose",	no_argument,		0,	'v'},
		{"count",	required_argument,	0,	'c'},
		{"interval",required_argument,	0,	'i'},
		{"ttl",	 	required_argument,	0,	'T'}, // 'T' est un code interne arbitraire pour ttl
		{"help",	no_argument,		0,	'?'},
		{"usage",	no_argument,		0,	'U'}, // 'U' arbitraire pour usage
		{"version",	no_argument,		0,	'V'},
		{0, 0, 0, 0} // Terminateur obligatoire
	};

	// c: et i: ont des arguments, v, V et ? n'en ont pas
	while ((flag = getopt_long(argc, argv, "vc:i:V?", long_options, NULL)) != -1) {
		switch (flag) {
			case 'v':
				opt.verbose = 1;
				break;
			case 'c':
				opt.count = atoi(optarg);
				break;
			case 'i':
				opt.interval = atof(optarg); // Support des flottants
				break;
			case 'T':
				opt.ttl = atoi(optarg);
				break;
			case 'V':
				printf("ping de golmon\n");
				exit(0);
			case 'U':
				printf(USAGE);
				exit(0);
			case '?':
				// Afficher l'aide complète type GNU ici
				printf(HELP);
				exit(0);
			default:
				// Sortie d'erreur standard 64 (EX_USAGE)
				fprintf(stderr, INFO);
				exit(64);
		}
	}
	if (optind != argc - 1) {
			printf("This version handle only one host\n" USAGE);
	   exit(EXIT_FAILURE);
	}
}
