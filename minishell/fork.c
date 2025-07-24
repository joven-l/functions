#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int	main(void)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		printf("%s\n", "child");
		exit(0);
	}
	waitpid(pid, NULL, 0);
	printf("%s\n", "aaa");
}