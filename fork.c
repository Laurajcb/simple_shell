#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int _strlen(char *str);

int main(void)
{
    int i = 1;
     char *prompt = "sh# ";
      char *buffer = NULL;
       size_t buffzise = 0;
        int characters;
         char* token[1024];

while(1)
{
    write(STDOUT_FILENO, prompt, _strlen(prompt));
     characters = getline(&buffer, &buffzise, stdin);
      token[0] = strtok(buffer, " ");
       if (execve(token[0], token, NULL) == -1);
       {
           perror("Error");
           i++;       
       }
       
   }
        free(buffer);  
}
