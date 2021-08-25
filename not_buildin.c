#include "shell.h"

/**
* not_buildin- function that check if comd is not boiulin
* @tokens: contais all the parameters gotten by the terminal
* Return: true if is not boitlin otherwise false
*/

int not_buildin(char **tokens)
{
	int i = 0;

	mybuild_t builints[] = {
		{"exit", _exitt},
		{"env", _env},
		{NULL, NULL},
	};

	for (i = 0; builints[i].type; i++)
	{
		if (_strcmp(builints[i].type, tokens[0]))
		{
			builints[i].func(tokens);
			return (false);
		}
	}
	return (true);
}

/**
* _env- function that shows the variables of the system
* Return: true if is not boitlin otherwise false
*/

void _env(char **tokens)
{
	int i = 0;

	(void)tokens;

	for (i = 0; environ[i] != NULL; i++)
	{
		_putstr(environ[i]);
		_putstr("\n");
	}
}

/**
* _exitt- exit the curren programm when is call it
* @tokens: contains the array of str input
* Return: void
*/

void _exitt(char **tokens)
{
	int status = errno;

	if (tokens[1] == NULL)
	{
		exit(status);
	}
	status = _atoi(tokens[1]);
	exit(status);
}
