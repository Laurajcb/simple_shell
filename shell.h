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
    char *imput_array;
    size_t imput_size;
} data_input_t;












/**
* funct_helpers
*/
int _putchar(char c);
int _strlen(char *s);

#endif
