#include "shell.h"

/**
* tokenize_getline- function that tokenize the line
* @data : contains all the parameters gotten by the terminal
* Return: the token
*/

char **tokenize_getline(data_input_t *data)
{
	char **token = malloc(sizeof(char *) * 1024);
	char *tmp = NULL;
	int i = 1;

	if (token == NULL)
	{
		return (NULL);
	}

	token[0] = strtok(data->input_array, " \n");
	tmp = data->input_array;
	while (tmp)
	{
		tmp = strtok(NULL, " \n");
		token[i] = tmp;
		i++;
	}
	return (token);
}
