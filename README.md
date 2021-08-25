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

![simple shell](flowchar..)

## Authors
- [_Angelica Rodiguez_](https://github.com/angelicarm3) - angie00069@gmail.com
- [_Carlos Matallana_](https://github.com/CarlosMatallana-prog) -3496@holbertonschool.com
- [_Laura Callejas_](https://github.com/Laurajcb) - callejaslaura96@gmail.com
