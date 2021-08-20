#include "shell.h"
/**
* execute- function that find the executable in the phats
* @_paths: where we going to look for 
* @path_file: is the path that contains the directory 
*             where we going to look for the ./ or thoken[0]
* @child_pid:is the process id to run the ./
*/
int execute(char **tokens, char *_paths)
{
   
    char *path;
    char *path_file = NULL;
    pid_t child_pid;
    int status;

    path = strtok(_paths, ":");
    while (path != NULL) 
    {
        path_file = _strncat(path, "/");
        path_file = _strncat(path_file, tokens[0]);
        
       
        if (access(path_file, F_OK) == 0)
        {
            child_pid = fork();
            if (child_pid == 0)
            {
                if (execve(path_file, tokens, NULL) == -1)
                {
                    
                    perror("Error");
                    return(-1);
                }
                return (0);
            }
            else
            {
                wait(&status);
                printf("Soy el padre: %d \n", status);
                if (status == 0)
                {
                    //printf("exitoso");//
                    return (0);
                }
                else
                {
                    printf("fallido\n");
                    return (-1);
                }
            }
        }

        
        path = strtok(NULL, ":");
    }
    
    free(path_file);
    return (-1);
}

