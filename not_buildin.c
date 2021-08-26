#include "shell.h"

/**
* noBuild - function that check if comd is not boiulin
* @tokens: contais all the parameters gotten by the terminal
* @count: ?
* @av: ?
* @_paths: ?
* @path_file: '
* @input_arr: ?
* Return: true if is not boitlin otherwise false
*/

int noBuild(char **tokens, int count, char *av, char *_paths,
	    char *path_file, char *input_arr)
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
			builints[i].func(tokens, count, av, _paths, path_file, input_arr);
			return (false);
		}
	}
	return (true);
}

/**
* _env- function that shows the variables of the system
* @tokens: contais all the parameters gotten by the terminal
* @count: ?
* @av: ?
* @_paths: ?
* @path_file: '
* @input_arr: ?
* Return: true if is not boitlin otherwise false
*/

void _env(char **tokens, int count, char *av, char *_paths,
	  char *path_file, char *input_arr)
{
	int i = 0;
	(void)tokens;
	(void)count;
	(void)av;
	(void)_paths;
	(void)path_file;
	(void)input_arr;

	for (i = 0; environ[i] != NULL; i++)
	{
		_putstr(environ[i]);
		_putstr("\n");
	}
}

/**
* _exitt- exit the curren programm when is call it
* @tokens: contais all the parameters gotten by the terminal
* @count: ?
* @av: ?
* @_paths: ?
* @path_file: '
* @input_arr: ?
* Return: void
*/

void _exitt(char **tokens, int count, char *av, char *_paths,
	    char *path_file, char *input_arr)
{
	int status = errno;
	int i = 0;

	if (tokens[1] == NULL)
	{
		FREEDATA(input_arr, _paths, tokens);
		exit(status);
	}
	else
	{
		for (i = 0; tokens[1][i] != '\0'; i++)
		{
			if (tokens[1][i] < 48 || tokens[1][i] > 57)
			{
				d_printf(STDERR_FILENO, ILLEGAL, av, count, tokens[1]);
				return;
			}
		}
	}

	status = _atoi(tokens[1]);
	FREEDATA(path_file, _paths, tokens);
	free(input_arr);
	exit(status);
}
