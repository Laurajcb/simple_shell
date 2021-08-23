#include "shell.h"

int check_file(char *path_file, int count, char *executable)
{
    (void)executable;
    
    if (access(path_file, R_OK) == 0)
    {

        if (access(path_file, X_OK) == 0)
        {
            return (true);
        }
        else
        {
            if (access(path_file, R_OK) == -1)
                d_printf(STDERR_FILENO, "%s: %d: Permission denied\n", path_file, count);
            return (false);
        }
    }
    else
    {
      d_printf(STDERR_FILENO, "%d: Can't open %s", count, path_file);
        return (false);
    }
}
