#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

// getcwd(null, 0) auto assigns enough memory
int	main(void)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	printf("%s\n", buf);
	free(buf);
	chdir("..");
	buf = getcwd(NULL, 0);
	printf("%s\n", buf);
	free(buf);
}