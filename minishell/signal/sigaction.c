#include <stdio.h> 
#include <signal.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//struct sigaction {
//    void (*sa_handler)(int);
//    void (*sa_sigaction)(int, siginfo_t *, void *);
//    sigset_t sa_mask;
//    int sa_flags;
//    void (*sa_restorer)(void);
//}

// To have read() return EINTR, unset SA_RESTART in the member 
// sa_flags of the struct sigaction passed into the call to 
// sigaction() when installing the signal handler for SIGINT.
// memset 0 auto unsets

void	handler(int sig)
{
	printf("sig: %d\n", sig);
}

int	main(void)
{
	struct sigaction erm;
	memset(&erm, 0, sizeof(erm));
	erm.sa_handler = handler;
	// erm.sa_flags = SA_RESTART;
	sigaction(SIGINT, &erm, NULL); // ctrl + "c"
	char buf[5];
	read(0, buf, 4);
	printf("RETURN");
	return 0; 
}
