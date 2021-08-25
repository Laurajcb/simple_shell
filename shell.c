#include "shell.h"
/**
* main- function emulates a shell
* Return: 0 on succes otherwise -1.
* @ac: argument counter
* @av: argument vector
*/
int main(int ac __attribute__((unused)), char **av)
{
	int readed_chars = 0, count = 0;
	char **tokens = NULL, *path_file = NULL, *_paths = NULL;
	data_input_t data_line = {NULL, 0};

	for (errno = 0; readed_chars != EOF; count++)
	{
		prompt();
		readed_chars = get_promptline(&data_line);
		if (readed_chars <= 1)
			continue;
		tokens = tokenize_getline(&data_line);
		if (tokens == NULL)
			continue;
		remove_spaces(tokens[0]);
		if (not_buildin(tokens, count, av[0], _paths, path_file, data_line.input_array))
		{
			_paths = get_env_var("PATH=");
			if (_paths == NULL)
			{
				free(tokens);
				continue;
			}
			path_file = find_pathfile(tokens, _paths);
			if (path_file == NULL)
			{
				d_printf(STDERR_FILENO, NOTFOUND, av[0], count, tokens[0]);
				FREEDATA(path_file, _paths, tokens);
				continue;
			}
			if (check_file(path_file, count, tokens[0], av[0]))
			{
				FREEDATA(path_file, _paths, tokens);
				continue;
			}
			run_script(path_file, tokens, av[0]);
			FREEDATA(path_file, _paths, tokens);
		}
	}
	free(data_line.input_array);
	return (0);
}
