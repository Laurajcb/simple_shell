#include "shell.h"
/**
* main- function emulates a shell
* Return: 0 on succes otherwise -1.
*/
int main(int ac, char **av)
{
	int readed_chars = 0;
	int  count = 0; 
	char **tokens = NULL;
	data_input_t data_line = {NULL, 0};
	char *path_file = NULL, *_paths = NULL;
	errno = 0;
	(void)ac;

	/*data_line = malloc(sizeof(data_input_t));*/
	/*if (data_line == NULL)
		return (-1);*/

	while (readed_chars != EOF)
	{
		prompt();
		readed_chars = get_promptline(&data_line);
		count++;
		if (readed_chars == -1)
			continue;
		if (readed_chars == 1)
			continue;
		tokens = tokenize_getline(&data_line);
		if (tokens[0] == NULL) continue;
		
		remove_spaces(tokens[0]);
		if (not_buildin(tokens))
		{
			_paths = get_env_var("PATH");
			path_file = find_pathfile(tokens, _paths);
			if (path_file == NULL) continue;
			if (check_file(path_file, count, tokens[0], av[0]) == false) continue;
			run_script(path_file, tokens, av[0]);

		}

	}
	free(data_line.input_array);
	free(_paths);
	return (0);
}
