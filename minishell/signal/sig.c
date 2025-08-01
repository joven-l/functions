#include <stdio.h> 
#include <signal.h> 
#include <stdlib.h>
#include <unistd.h>

void	handler(int sig)
{
	printf("sig: %d\n", sig);
}

int	main(void)
{
	signal(SIGINT, handler); // ctrl + "c"
	signal(SIGQUIT, handler); // ctrl + "\"
	char buf[5];
	read(0, buf, 4);
	printf("RETURN");
	return 0; 
}
