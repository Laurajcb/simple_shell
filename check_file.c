#include "shell.h"

/**
* check_file- function that check the path
* @path_file: contains all the parameters gotten by the terminal
* @tokens: contains all the parameters gotten by the terminal
* @count: contains all the parameters gotten by the terminal
* @executable: contains all the parameters gotten by the terminal
* Return: the token
*/

int check_file(char *path_file, int count, char *executable, char *tokens)
{
	if (access(path_file, F_OK) == 0 && access(path_file, X_OK) == -1)
	{
		d_printf(STDERR_FILENO, DENIED, executable, count, tokens);
		return (true);
	}
	else if (access(path_file, F_OK) == 0 && access(path_file, R_OK) == -1)
	{
		d_printf(STDERR_FILENO, NOREAD, tokens, count, executable);
		return (true);
	}
	else if (_strlen(tokens) >= 256)
	{
		d_printf(STDERR_FILENO, TOOLONG, count - 1, path_file);
		return (true);
	}
	else if (access(path_file, F_OK) == -1)
	{
		d_printf(STDERR_FILENO, NOTFOUND, executable, count, path_file);
		return (true);
	}
	return (false);
	/*
	*else
	*{
	*	if (access(path_file, R_OK) == -1)
	*		d_printf(STDERR_FILENO, "%d: %d: Can't open\n", 22, path_file);
	*	return (false);
	*}
	*/
}
