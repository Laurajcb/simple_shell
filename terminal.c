#include "shell.h"

/**el tercer argumento es un doble puntero 
 *osea un array de strings que contiene las variables de entorno
 *en ellas el PATH donde budcaremos los ejecutables
*/

int main(void)
{
	int i = 1;
	int readed_chars = 0;
	char **tokens = NULL;
	
	data_input_t *data_line;

	data_line = malloc(sizeof(data_input_t));
	if (data_line == NULL)
	{
		return (-1);
	}
	while (readed_chars != -1)
	{
		//the prompt function
		_prompt();
		readed_chars = _get_promptline(data_line);
		if (readed_chars == -1)
		{
			return (-1);
		}
		//tokenize the getline
		tokens = tokenize_getline(data_line);
		if (not_buildin(tokens))
		{
			get_dir(tokens); //path & dir ./ to be replaced tokens[1]
			execute(tokens); // use with fork and execute in child 
		}

		//validate if is one built-in else built-in create fork and execute in child
		if (execve(tokens[0], tokens, NULL) == -1)
			perror("Error");
	}
	free(data_line);
	return (0);
}