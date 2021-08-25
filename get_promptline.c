#include "shell.h"

/**
* get_promptline- read the line, and assing the values
* @data: is the object that contains the line
* Return: the chars readed
*/

ssize_t get_promptline(data_input_t *data)
{
	ssize_t readed_char = 0;
	int i = 0;

	readed_char = getline(&(data->input_array), &(data->input_size), stdin);
	if (readed_char > 0)
	{
		data->input_array[readed_char - 1] = '\0';
		for (i = 0; data->input_array[i]; i++)
		{
			if (data->input_array[i] != ' ')
			{
				break;
			}
		}
		if (data->input_array[i] == '\0')
		{
			return (0);
		}
	}
	return (readed_char);
}
