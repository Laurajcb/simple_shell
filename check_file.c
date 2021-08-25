#include "shell.h"

int check_file(char *path_file)
{
	if (access(path_file, F_OK) == 0)
	{

		if (access(path_file, X_OK) == 0)
		{
			return (true);
		}
	}	
	return (0);
}
