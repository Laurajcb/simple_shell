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
	char **tokens = NULL, *path_fl = NULL, *paths = NULL;
	data_input_t data_ln = {NULL, 0};

	for (errno = 0; readed_chars != EOF; count++)
	{
		prompt();
		readed_chars = get_promptline(&data_ln);
		if (readed_chars <= 1)
			continue;
		tokens = tokenize_getline(&data_ln);
		if (tokens == NULL)
			continue;
		remove_spaces(tokens[0]);
		if (noBuild(tokens, count, av[0], paths, path_fl, data_ln.input_array))
		{
			paths = get_env_var("PATH=");
			if (paths == NULL)
			{
				free(tokens);
				continue;
			}
			path_fl = find_pathfile(tokens, paths);
			if (path_fl == NULL)
			{
				d_printf(STDERR_FILENO, NOTFOUND, av[0], count, tokens[0]);
				FREEDATA(NULL, paths, tokens);
				continue;
			}
			if (check_file(path_fl, count, tokens[0], av[0]))
			{
				FREEDATA(path_fl, paths, tokens);
				continue;
			}
			run_script(path_fl, tokens, av[0]);
			FREEDATA(path_fl, paths, tokens);
		}
	}
	free(data_ln.input_array);
	return (0);
}
