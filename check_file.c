#include "shell.h"

/**
* check_file - Function that check the possible error at execute a file
*
* @path_file: the executable path
* @count: the number of the line in the prompt
* @executable: the name of executable of the shell
* @tokens: user input commands
*
* Return: 1 if Success | 0 if fail
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
}
