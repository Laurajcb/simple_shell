#include "shell.h"

/**
* getline - prints the prompt of the shell 
* Return : void
*/

int _get_promptline(data_input_t *data)
{   
    char *line = NULL;
    size_t lineSize = 0;
    int readed_char = 0;

    readed_char = getline(&line, &lineSize, stdin);
    line[readed_char -1] = '\0';

    data->input_array = line;
    data->input_size = lineSize;

    return(readed_char);
}