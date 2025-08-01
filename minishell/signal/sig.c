#include <stdio.h> 
#include <signal.h> 
#include <stdlib.h>

void	handler(int sig)
{
	printf("sig: %d\n", sig);
	exit(sig);
}

int	main(void)
{
	signal(SIGINT, handler); // ctrl + "c"
	signal(SIGQUIT, handler); // ctrl + "\"
	while (1)
		printf("erm\n"); 
	return 0; 
}
