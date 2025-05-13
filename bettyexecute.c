#include "shell.h"

/**
 * execute - Creates a child process and executes a command.
 * @args: Null-terminated array of argument strings. The first element
 *        should be the path to the command.
 *
 * Description: This function forks the current process. The child process
 * attempts to execute the command using execve. If the fork or execve
 * call fails, appropriate error messages are printed using perror.
 */
void execute(char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
	}
	else if (child_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}

