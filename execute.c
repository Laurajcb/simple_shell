#include "shell.h"

int execute(char **tokens, char *_paths)
{
    printf("paths: %s\n", _paths);
    char *path;
    char *path_file = NULL;

    path = strtok(_paths, ":");
    while (path != NULL)
    {
        path_file = _strncat(path, "/");
        path_file = _strncat(path_file, tokens[0]);

        if (access(path_file, F_OK) == 0)
        {
            printf("path_file: %s\n", path_file);
            printf("La ruta existe\n");
            return (1);
        }

        //printf("im a path = %s, file: %s\n", path, tokens[0]);
        path = strtok(NULL, ":");
    }

    free(path_file);
    return (0);
}
