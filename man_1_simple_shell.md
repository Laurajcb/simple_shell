% SIMPLESHELL(1) 1.0
% Carlos Matallana, Laura Callejas, Angelica Rodriguez
% August 2021

# NAME
sh - shell, the standard command language interpreter

# SYNOPSIS
#include "shell.h"

# DESCRIPTION
The sh is a command language interpreter that shall execute commands read from a command line string, the standard input, or a specified file.

It should be compiled this way:
   	      gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.h *.c -o hsh

This shell works in both, interactive and non-interactive mode.
     Example:
	      (Interactive Mode)
	      $ ./hsh
	      ($) /bin/ls
	      hsh main.c shell.c
	      ($)
	      ($) exit
	      $

	      (Non-interactive Mode)
	      $ echo "/bin/ls" | ./hsh
	      hsh main.c shell.c test_ls_2
	      $
	      $ cat test_ls_2
	      /bin/ls
	      /bin/ls
	      $
	      $ cat test_ls_2 | ./hsh
	      hsh main.c shell.c test_ls_2
	      hsh main.c shell.c test_ls_2
	      $

The user can exit the program by typing the command "exit" or Ctrl + D

# BUGS
No known bugs

# COPYRIGHT
Copyright ® 2021 Carlos Matallana, Laura Callejas, Angelica Rodriguez. This is free software: you are free to change and redistribute it. There is no WARRANTY, to the extent permitted by law.