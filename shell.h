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
#include <stdarg.h>
#include <fcntl.h>
#include <stddef.h>




#define PROMPT ("$ ")
#define true (1)
#define false (0)

extern char **environ;

/**
 * struct data_input- has the input
 * @input_array:it has the line gotten by getline
 * @input_size: it has the number of chars
 * Description: struct contains the info about readed a line
 */
typedef struct data_input
{
	char *input_array;
	size_t input_size;
} data_input_t;


int get_promptline(data_input_t *data);
void prompt(void);
int not_buildin(char **tokens);
char **tokenize_getline(data_input_t *data);
char *get_env_var(char *var_name);
void get_dir(char **tokens);
void run_script(char *path_file, char **tokens);
char *find_pathfile(char **tokens, char *_paths);
void replace_var(char **tokens);
int check_file(char *path_file, int count, char *executable);

/**
 * struct mybuild- has the builtin funct
 * @type:is the identifier of the cmd
 * @func: is the function
 * Description: struct contains the info to do the builtin cmds
 */
typedef struct mybuild
{
	char *type;
	void (*func)(char **tokens);
} mybuild_t;


void _exitt(char **tokens);
void _env();



int _putchar(char c);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int intlen(int num);
int _atoi(char *c);
void _putstr(char *str);
char *_strcpy(char *dest, char *src);
char *_strncat(char *dest, char *src);
void remove_spaces(char *str);
void reverse(char *str, int len);
int int_to_str(int x, char str[]);
int d_printf (int fd, const char *format, ...);


#endif
