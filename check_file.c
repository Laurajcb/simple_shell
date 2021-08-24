#include "shell.h"

int check_file(char *path_file, int count, char *token, char *executable)
{

	if (access(path_file, F_OK) == 0)
	{

		if (access(path_file, X_OK) == 0)
		{
			return (true);
		}
		else if (access(path_file, X_OK) == -1)
		{
			d_printf(STDERR_FILENO, "%s: %d: %s: Permission denied\n", executable, count, path_file);
		}
		else if (access(path_file, R_OK) == -1)
		{
			d_printf(STDERR_FILENO, "%s: 0: Can't open %s\n", executable, path_file);
		}
		else if (_strlen(token) >= 256)
		{
			d_printf(STDERR_FILENO, "%s: %d: %s: File name too long\n",executable, count - 1, path_file);
		}
		else if (access(path_file, F_OK) == -1)
		{
			d_printf(STDERR_FILENO, "%s: %d: %s: not found\n", executable, count - 1, path_file);
		}
		else
		{
			if (access(path_file, R_OK) == -1)
				d_printf(STDERR_FILENO, "%d: %d: Can't open\n", 22, path_file);
			return (false);
		}
	}
	else
	{
		d_printf(STDERR_FILENO, "%s: %d: Can't open %s\n", executable, count, path_file);
		return (false);
	}
}
