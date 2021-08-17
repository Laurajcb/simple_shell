#include "shell.h"

/**
* _get_params- get the parameters 
* Return : void
*/
char **main(void)
{
	char **tokens;
	char *token;
	int i, buffsize = 1024;
    char *input = "hola comi estan ?";

	if (input == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	token = strtok(input, "\n ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, "\n ");
	}
	tokens[i] = NULL;
    printf("%s\n", tokens[0]);
    printf("%s\n", tokens[1]);
    printf("%s\n", tokens[2]);
    printf("%s\n", tokens[3]);

	return (tokens);
}
/*char **_get_params(data_input_t *data)//
char* main(void)
{
    //char *line = data->input_array;//
    char *line = "Hola como estan todos ?";
    char **params;
    char *token;
    
    

    
    token = strtok(line, " ");
    params[0] = token;

    /*while (token)
    {

        params[i] = token;
        i++;
        token = strtok(NULL, "\n  ");
    }
    printf("%s\n", params[0]);
    printf("%s\n", params[1]);
    printf("%s\n", params[2]);
    printf("%s\n", params[3]);

    return (token);
    //params/
}*/