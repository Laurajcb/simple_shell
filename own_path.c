#include "shell.h"

/**
 * own_path-function to get the env
 * 
 */

extern char **environ;

char **own_path(char *VarName)
{
    int i = 0;

    char *token;
    char *copy = malloc(sizeof(char) * 1024);

    for (i = 0; environ[i] != NULL; i++)
    {
        _strcpy(copy, environ[i]);
        token = strtok(copy, "=");
        token = strtok(NULL, "=");
    }
}
