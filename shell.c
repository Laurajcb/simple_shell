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
	data_input_t *data_line;
	char *path_file, *_paths = malloc(sizeof(char) * 1024);
	errno = 0;
	(void)ac;
	(void)av;

	if (_paths == NULL)
		return (-1);

	data_line = malloc(sizeof(data_input_t));
	if (data_line == NULL)
		return (-1);

	while (readed_chars != EOF)
	{
		prompt();
		readed_chars = get_promptline(data_line);
		count++;
		if (readed_chars == -1)
			return (-1);
		if (readed_chars == 1)
			continue;
		tokens = tokenize_getline(data_line);
		if (tokens[0] == NULL) continue;
		
		remove_spaces(tokens[0]);
		if (not_buildin(tokens))
		{
			_paths = get_env_var("PATH");
			path_file = find_pathfile(tokens, _paths);
			if (path_file == NULL) continue;
			if (check_file(path_file, count -1, " ") == false) continue;
			run_script(path_file, tokens);
		}

	}
	free(readed_chars); /*@TODO revisar free buffer of getline*/
	free(data_line);
	free(_paths);
	return (0);
}
