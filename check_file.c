#include "shell.h"

int check_file(char *path_file)
{
    if (access(path_file, R_OK) == 0)
    {

        if (access(path_file, X_OK) == 0)
        {
            return (true);
        }
        else
        {
            perror("Error no ./");
            return (false);
        }
    }
    else
    {
        perror("0: Can't open ");
        return (false);
    }
}
