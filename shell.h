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
#define PROMPT ("$ ")
#define true (1)
#define false (!true)


extern char **environ;

/**
 * struct env_var - enviroment vars
 * Description: struct have ...
 */
typedef struct data_input
{
	char *input_array;
	size_t input_size;
} data_input_t;

/**
* main functions
*/

int _get_promptline(data_input_t *data);
void _prompt(void);
char *_get_params(data_input_t *data);
char **tokenize_getline(data_input_t *data);




/**
* struct para my build-in 
*/
typedef struct mybuild
{
	char *type;
	void (*func)(char **tokens);
} mybuild_t;
/**
* functions that cointains  buil-in functions
*/
void _exitt(char **tokens);
void _env(char **tokens);


/**
* funct_helpers
*/
int _putchar(char c);
int _strlen(char *s);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
void _putstr(char *str);



#endif
