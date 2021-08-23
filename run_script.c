#include "shell.h"

/**
* run_script- function that find the executable in the paths
* @tokens: contais all the parameters gotten by the terminal
* @path_file: where we going to look for
* Return: true on succes otherwise -1.
*/

void run_script(char *path_file, char **tokens)
{
	pid_t child_pid = 0;
	int status = 0;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(path_file, tokens, NULL) == -1)
		{
			printf("Error");
			
		}
		exit(errno);
	}
	else
	{
		wait(&status);
		
	}
	
}
