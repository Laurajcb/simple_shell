#include "shell.h"

/**
* run_script- function that find the executable in the phats
* @tokens: contais all the parameters gotten by the terminal
* @path_file: where we going to look for
* Return: true on succes otherwise -1.
*/

int run_script(char *path_file, char **tokens)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(path_file, tokens, NULL) == -1)
		{
			perror("Error");
			return (-1);
		}
		return (true);
	}
	else
	{
		wait(&status);
		if (status == 0)
			return (true);

		else
		{
			printf("fallido\n");
			return (-1);
		}
	}
}
