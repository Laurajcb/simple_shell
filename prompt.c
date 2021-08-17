#include "shell.h"

/**
* prompt - prints the prompt of the shell
* Return : void
*/

void _prompt(void)
{
	if (isatty(STDOUT_FILENO))
	{
		write(STDOUT_FILENO, PROMPT, _strlen(PROMPT));
	}
}
