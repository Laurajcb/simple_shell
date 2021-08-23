#include "shell.h"

/**
 * replace_var-function find a char an replaced by the value
 * @tokens:is the key that we'll be fix
 
 * Return: NULL if didn't found the key otherewise the value
 */
void replace_var(char **tokens)
{
    int i = 0, j;
    char *var = malloc(sizeof(char) * 2048);
    char *copy = malloc(sizeof(char) * 2048);
    if (copy == NULL) return;
    if (var == NULL) return;

    for (i = 0; tokens[i] != NULL; i++)
    {
        if (tokens[i][0] == '$')
        {
            for (j = 1; tokens[i][j] != '\0'; j++)
            {
                copy[j - 1] = tokens[i][j];
            }
            copy[j - 1] = '\0';

            var = get_env_var(copy);
            tokens[i] = var;
        }
    }
    
}
