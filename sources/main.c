#include <stdio.h>
#include <stdlib.h>

#include <ping.h>
// checker les flags
// ouvrir une socket
int	main(int argc, char **argv)
{
	if (argc != 2) {
	   fprintf(stderr, "Usage: %s host port msg...\n", argv[0]);
	   exit(EXIT_FAILURE);
	}
	check_flags();
	printf("Hello world !\n");
	return (EXIT_SUCCESS);
}
