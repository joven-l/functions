#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	fd[2];

	if (pipe(fd) == -1)
	{
		printf("%s\n", "break");
	}
	write(fd[1], "ermm", 4);
	close(fd[1]);
	char *buffer = malloc(sizeof(char) * (4 + 1));
	read(fd[0], buffer, 4);
	buffer[4] = '\0';
	printf("%s\n", buffer);
}