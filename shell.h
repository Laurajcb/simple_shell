#ifndef SHELL_H
#define SHELL_H

/**
 * Header File - shell.h
 * Authors: Edisson Osorio & Laura Callejas 
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <limits.h>
#define PROMPT "$ "
#define DELIMIT " "

/**
 * struct env_var - enviroment vars
 * Description: struct have all the shell vars env.
 * this struct is goint to be use in functions to get 
 * the all the shell env 
 */
typedef struct data_input
{
	char *input_array;
	size_t input_size;
} data_input_t;



int _get_promptline(data_input_t *data);
void _prompt(void);
/**
* funct_helpers
*/
int _putchar(char c);
int _strlen(char *s);
char *_strchr(char *s, char c);
int _strncmp(char *s1, char *s2, int n);

#endif
