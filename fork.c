#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 *_strlen - return the length of a string
 *@s: character
 *Return: length os string
 */
int _strlen(char *s)
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        ;
    }
    return (i);
}
/**el tercer argumento es un doble puntero 
 *osea un array de strings que contiene las variables de entorno
 *en ellas el PATH donde budcaremos los ejecutables
*/

int main(void)
{
    int i = 1;
    char *prompt = "$";
    char *buffer = NULL;
    size_t buffzise = 0;
    int characters;
    char *token[1024];
    char *tmp;

    while (1)
    {
        //the prompt function
        write(STDOUT_FILENO, prompt, _strlen(prompt));
        characters = getline(&buffer, &buffzise, stdin);
        //tokenize the getline
        token[0] = strtok(buffer, " \n"); 
        tmp = buffer;
        while (tmp)
        {

            tmp = strtok(NULL, " \n");
            token[i] = tmp;
           
            i++;
        }
        //validate if is one built-in else built-in create fork and execute in child
        if(execve(token[0], token, NULL) == -1)
                perror("Error");
    }
    free(buffer);
    return (0);
}