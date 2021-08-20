#include "shell.h"

/**
 * get_env_var-function to get the value of the respective key in the ENVIRONS 
 * @var_name:is the key that we'll be search
 * @key: is the name of the current var
 * @value:is the value of the environment key
 * @current_env: where we are looking the key
 * Return: NULL if didn't found the key otherewise the value 
 */

extern char **environ;
char *get_env_var(char *var_name)
{
    int i = 0;
    char *key;
    char *value;
    char *current_env = malloc(sizeof(char) * 2048);

    for (i = 0; environ[i] != NULL; i++)
    {
        _strcpy(current_env, environ[i]);
        key = strtok(current_env, "=");
        if (_strcmp(var_name, key))
        {
            value = strtok(NULL, "\n");
            printf("Im the value of the key in te current env: %s\n", value);
            free(current_env);
            return(value);
        }
    }

    free(current_env);
    return (NULL);
}
