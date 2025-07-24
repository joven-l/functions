#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char *buf;

	buf = getenv("PATH");
	printf("%s\n", buf);
}
