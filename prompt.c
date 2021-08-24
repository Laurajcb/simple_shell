#include "shell.h"
#include <unistd.h>

/**
* prompt - prints the prompt of the shell
* Return : void
*/

void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, PROMPT, _strlen(PROMPT));
	}
}
