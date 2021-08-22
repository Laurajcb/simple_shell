#include "shell.h"
/**
* find_pathfile- function that find the executable full path
* @tokens: contais all the parameters gotten by the terminal
* @_paths: where we going to look for
* Return: path file or -1 if is not found.
*/
char *find_pathfile(char **tokens, char *_paths)
{
	char *path;
	char *path_file = NULL;
	

	path = strtok(_paths, ":");
	while (path != NULL)
	{
		path_file = _strncat(path, "/");
		path_file = _strncat(path_file, tokens[0]);

		if (access(path_file, F_OK) == 0)
		{
			return (path_file);
		}
		path = strtok(NULL, ":");
	}
	return (NULL);
}
