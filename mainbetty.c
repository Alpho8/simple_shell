#include "shell.h"


/**
 * main - Entry point of a simple shell program.
 *
 * Description: Continuously prompts the user for input, reads a line,
 * tokenizes it, and executes the resulting command. The loop runs
 * until getline fails (e.g., EOF or error). Memory is properly
 * managed to avoid leaks.
 *
 * Return: Always returns 0 on success.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$", 2);
		}
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			break;
		}

		args = tokenize(line);
		if (args && args[0] && _strcmp(args[0], "exit") == 0)
		{
			free(args);
			break;
		}
		if (args && args[0] != NULL)
			execute(args);

		free(args);
	}

	free(line);
	return (0);
}

