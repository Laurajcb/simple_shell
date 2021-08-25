#include "shell.h"
/**
* find_pathfile- function that find the executable full path
* @tokens: contais all the parameters gotten by the terminal
* @_paths: where we going to look for
* Return: path file or -1 if is not found.
*/
char *find_pathfile(char **tokens, char *_paths)
{
	char *path = NULL;
	char *first_concat = NULL;
	char *path_file = NULL;

	if (access(tokens[0], F_OK) == 0)
	{
		path_file = _strncat(tokens[0], "");
		return (path_file);
	}

	path = strtok(_paths, ":");
	while (path != NULL)
	{
		first_concat = _strncat(path, "/");
		path_file = _strncat(first_concat, tokens[0]);
		free(first_concat);

		if (access(path_file, F_OK) == 0)
		{
			return (path_file);
		}
		path = strtok(NULL, ":");
		free(path_file);
		path_file = NULL;
	}
	return (NULL);
}
