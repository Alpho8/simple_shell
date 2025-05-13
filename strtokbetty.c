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
	if (token)
		tokens[i++] = token;
	token = strtok(NULL, " \t\r\n");
	if (token != NULL)
	{
		return (NULL);
	}
	tokens[i] = NULL;
	return (tokens);
}

