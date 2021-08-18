#include "shell.h"
// #define TESTING_OF_TOKENIZE

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

#ifdef TESTING_OF_TOKENIZE
int main(int argc, char **argv)
{
    (void)argc;
    char **tokens = NULL;
    int i = 0;

    data_input_t *data_line = NULL;

    data_line = malloc(sizeof(data_input_t));
    if (data_line == NULL)
    {
        return (-1);
    }
    data_line->input_array = argv[1];
    tokens = tokenize_getline(data_line);
    while (tokens[i])
    {
        printf("%s\n", tokens[i]);
        i++;
    }
    return (0);
}

#endif