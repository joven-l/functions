#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

// compile with -lreadline
// this is just read from stdin but better
int	main(void)
{
	char	*line;

	while (1)
	{
		line = readline("erm>");
		printf("%s\n", line);

		// up arrow history
		if (line != NULL)
			add_history(line);
		else
			break;
		// ctrl+d = NULL
		free(line);
	}
	rl_clear_history();
}

