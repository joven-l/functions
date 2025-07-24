#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

// idk what use this has
int	main(void)
{
	struct stat stats;
	char	buf[PATH_MAX];

	getcwd(buf, sizeof(buf));
	strcat(buf, "/stat.c");
	printf("%s, %d\n", buf, stat(buf, &stats));

	getcwd(buf, sizeof(buf));
	strcat(buf, "/empty");
	printf("%s, %d\n", buf, stat(buf, &stats));
}
