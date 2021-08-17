#include "shell.h"

/**el tercer argumento es un doble puntero 
 *osea un array de strings que contiene las variables de entorno
 *en ellas el PATH donde budcaremos los ejecutables
*/

int main(void)
{
	int i = 1;
	int readed_chars;
	char *token[1024];
	char *tmp;
	data_input_t *data_line;

	data_line = malloc(sizeof(data_input_t));
	if (data_line == NULL)
	{
		return (-1);
	}
	while (1)
	{
		//the prompt function
		_prompt();
		readed_chars = _get_promptline(data_line);
		if (readed_chars == -1)
		{
			return (-1);
		}
		//tokenize the getline
		token[0] = strtok(data_line->input_array, " \n");
		tmp = data_line->input_array;
		while (tmp)
		{
			tmp = strtok(NULL, " \n");
			token[i] = tmp;
			i++;
		}

		//validate if is one built-in else built-in create fork and execute in child
		if (execve(token[0], token, NULL) == -1)
			perror("Error");
	}
	free(data_line);
	return (0);
}