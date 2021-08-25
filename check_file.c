#include "shell.h"

/**
* checkFile - ?
*
* @path_file: ?
* @count: ¡
* @executable: ?
*
* Return: ?
*/
int checkFile(char *path_file, int count, char *executable)
{
	(void)executable;

	if (access(path_file, R_OK) == 0)
	{
		if (access(path_file, X_OK) == 0)
		{
			return (true);
		}
		else
		{
			if (access(path_file, R_OK) == -1)
				d_printf(STDERR_FILENO, "%s: %d: Permission denied\n", path_file, count);
			return (false);
		}
	}
	else
	{
		d_printf(STDERR_FILENO, "%d: Can't open %s\n", count, path_file);
		return (false);
	}
}

