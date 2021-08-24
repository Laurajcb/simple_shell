#include "shell.h"

int check_file(char *path_file, int count, char *token, char *executable)
{
	printf("Este es count %d:\n",count);
	if (access(path_file, F_OK) == 0)
	{

		if (access(path_file, X_OK) == 0)
		{
			return (true);
		}
		else if (access(path_file, X_OK) == -1)
		{
			d_printf(STDERR_FILENO, "%s: %d: %s  Permission denied\n", executable, count, token);
			/*to check */
		}
		else if (access(path_file, R_OK) == -1)
		{
			d_printf(STDERR_FILENO, "%s: 0: Can't open %s\n", executable, path_file);
		}
		else if (_strlen(token) >= 256)
		{
			d_printf(STDERR_FILENO, "%d: %s: File name too long\n", count - 1, path_file);
		}
		else if (access(path_file, F_OK) == -1)
		{
			d_printf(STDERR_FILENO, "%d: %s: not found\n", count - 1, path_file);
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
	return (0);
}
