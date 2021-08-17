#include "shell.h"

/**
* prompt - prints the prompt of the shell '$'
* Return : void
*/
void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		_putchar('$');
	}
}
