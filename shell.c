#include "shell.h"
/**
* main- function emulates a shell
* @argc: is the counter of argv
* @argv: is the string of params
* Return: 0 on succes otherwise -1.
*/
int main(int argc, char **argv)
{
	int i = 1;
	int readed_chars = 0;
	char **tokens = NULL;
	data_input_t *data_line;
	char *executable_path = *argv; //to handle errors in the future//
	char *path_file, *_paths = malloc(sizeof(char) * 1024);

	if (_paths == NULL)
		return (-1);

	(void)argc;

	data_line = malloc(sizeof(data_input_t));
	if (data_line == NULL)
		return (-1);

	while (readed_chars != -1)
	{
		_prompt();
		readed_chars = _get_promptline(data_line);
		if (readed_chars == -1)
			return (-1);
		if (readed_chars == 1)
			continue;

		tokens = tokenize_getline(data_line);
		if (not_buildin(tokens))
		{
			_paths = get_env_var("PATH");
			path_file = find_pathfile(tokens, _paths);
			run_script(path_file, tokens);
		}
	}
	free(data_line);
	free(_paths);
	return (0);
}
