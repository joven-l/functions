#include <stdio.h> 
#include <signal.h> 
#include <stdlib.h>

int	y;

void	handler(int sig)
{
	printf("sig: %d\n", sig);
	y = 1;
}
void	handler2(int sig)
{
	printf("sig2: %d\n", sig);
	y = 1;
}

int	main(void)
{
	signal(SIGINT, handler); // ctrl + "c"
	signal(SIGQUIT, handler); // ctrl + "\"
	int i = 0;
	y = 0;
	while (y != 1)
		i++;
	signal(SIGINT, handler2); // ctrl + "c"
	signal(SIGQUIT, handler2); // ctrl + "\"
	y = 0;
	while (y != 1)
		i++;
	signal(SIGINT, handler); // ctrl + "c"
	signal(SIGQUIT, handler); // ctrl + "\"
	y = 0;
	while (y != 1)
		i++;
	return 0; 
}
