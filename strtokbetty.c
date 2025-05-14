#include "shell.h"

/**
 * tokenize - Splits a line into tokens (words).
 * @line: The input line to tokenize.
 *
 * Description: Uses strtok to split the input line based on whitespace
 * characters (space, tab, carriage return, newline). Allocates and
 * resizes memory as needed to hold all tokens.
 *
 * Return: A null-terminated array of strings (tokens).
 */
char **tokenize(char *line)
{
	int bufsize = 64, i = 0;
	char **tokens = malloc(sizeof(char *) * bufsize);
	char *token;

	if (!tokens)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\r\n");
	while (token != NULL)
	{
		tokens[i++] = token;
		if (i >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!token)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\r\n");
	}
	tokens[i] = NULL;
	return (tokens);
}

