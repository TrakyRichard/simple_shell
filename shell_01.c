#include "shell.h"

int main(void)
{
	char *arg[] = {NULL, NULL};
	char *command = NULL;
	size_t command_len = 0;
	ssize_t n = 0;
	while (1)
	{
		/* code */
		printf("Entrer une commande :");
		n_bytes = getline(&command, &command_len, stdin);
		command[n - 1] = '\0';

		arg[0] = command;

		execve(*arg, arg, NULL);
	}

	return (0);
}