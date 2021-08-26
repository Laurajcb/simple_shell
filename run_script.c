#include "shell.h"

/**
* run_script- function that find the executable in the paths
* @tokens: contais all the parameters gotten by the terminal
* @path_file: where we going to look for
* @av: argument vector.
* Return: true on succes otherwise -1.
*/

void run_script(char *path_file, char **tokens, char *av)
{
	pid_t child_pid = 0;
	int status = 0;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(path_file, tokens, environ) == -1)
		{
			d_printf(STDERR_FILENO, "%s: %s: Permission denied", av, tokens[0]);
		}
		exit(errno);
	}
	else
	{
		wait(&status);
	}
}
