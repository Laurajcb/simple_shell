#include "shell.h"
/**
* main- function emulates a shell
* Return: 0 on succes otherwise -1.
* @ac: argument counter
* @av: argument vector
*/
int main(int ac, char **av)
{
	int readed_chars = 0, count = 0;
	char **tokens = NULL, *path_file = NULL, *_paths = NULL;
	data_input_t data_line = {NULL, 0};

	errno = 0;
	(void)ac;
	
	while (readed_chars != EOF)
	{
		prompt();
		readed_chars = get_promptline(&data_line), count++;
		if (readed_chars <= 1)
			continue;
		tokens = tokenize_getline(&data_line);
		if (tokens == NULL)
			continue;
		remove_spaces(tokens[0]);
		if (not_buildin(tokens))
		{
			_paths = get_env_var("PATH");
			if (_paths == NULL) 
			{
				free(tokens);
				continue;
			}
			path_file = find_pathfile(tokens, _paths);
			if (path_file == NULL)
			{
				d_printf(STDERR_FILENO, NOTFOUND, av[0], count, tokens[0]);
				free(_paths);
				free(path_file);
				free(tokens);
				continue;
			}
			if (check_file(path_file, count, tokens[0], av[0]))
			{
				free(path_file);
				free(_paths);
				free(tokens);
				continue;
			}
			run_script(path_file, tokens, av[0]);
			free(_paths);
			free(path_file);
			free(tokens);
		}
	}
	free(data_line.input_array);
	return (0);
}
