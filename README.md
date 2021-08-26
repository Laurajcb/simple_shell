<p aling="center">
    <img  src="https://i0.wp.com/colaboratorio.net/wp-content/uploads/2017/01/bash.jpg?fit=2000%2C1200&ssl=1"
    width="400" height="200">
</p>

# **_Simple Shell Project_**

In this repository you will find our version of a simple UNIX commandinterpreter: Shell.

## Man Page

* To see the shell manual you must execute this command.

## Environment
```
 This project has been tested on `Ubuntu 14.06.6 LTS`
```
## Instructions
```
 *Compiling the program: gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

*Interactive mode:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

*Non-interactie mode:

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

```
## Files

| **NAME** | CONTENT |
|---|---|
|[_README.md_](./README.md)| It contains all the information about the project and all it's content
|[_shell.c_](./shell.c)| Is the main function of our project.|
|[_shell.h_](./shell.h)| It's the header of our project.|
|[_prompt_](./prompt.c)| Function that shows the '$' as our promp|
|[_getPromptLine_](./_get_promptline.c)|Function that reads the line, and assing the values|
|[_tokenizeGetline_](./tokenize_getline.c)|gets the tokens of the line|
|[_getEnvVar_](./getEnvVar.c)|Function to get the value of the respective key in the ENVIRONS|
|[_notBuildin_](./not_buildin.c)|Function that check if command is not built-in|
|[_findPathFile_](./findPathFile.c)|Function that find the executable full path|
|[_checkFile_](./checkFile.c)|Fuction to check if the file can be executable|
|[_env_](./_env.c)|Function that shows the variables of the system|
|[_exitt_](./exitt.c)|Function that exits the curren programm when is call it|
[_functHelpers_](./functHelpers.c)|Contains more functions that support the main ones|
|[_AUTHORS_](./AUTHORS)| File in which the people who contributed to this project are listed.|

## Flowchart

![simple shell](flowchar..![Image text](https://github.com/zzuljs/CppLearning/blob/master/CppLearning/raw/master/Itachi.jpg))

### Requirements
## General

Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 14.04 LTS
Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
No more than 5 functions per file
All your header files should be include guarded
Use system calls only when you need to (why?)
List of allowed functions and system calls

access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)



## Authors
- [_Angelica Rodiguez_](https://github.com/angelicarm3) - angie00069@gmail.com
- [_Carlos Matallana_](https://github.com/CarlosMatallana-prog) -3496@holbertonschool.com
- [_Laura Callejas_](https://github.com/Laurajcb) - callejaslaura96@gmail.com
