#include "shell.h"
//return 0 if is found otherwise 1//
// #define TESTING_OF_NO_BUITDINT
int not_buildin(char **tokens)
{
	int i = 0;
	
	printf("esta es al funcion no buldin\n");
	mybuild_t builints[] = {
		{"exit", _exitt},
		{"env", _env},
		{"env", _env},
		{"env", _env},
		{NULL, NULL},
	};
	for(i = 0; builints[i].type; i++)
	{
		if (_strcmp(builints[i].type ,tokens[0]))
		{
			builints[i].func(tokens);
			return (false);
		}
	} 
	return (true);
}
	
#ifdef TESTING_OF_NO_BUITDINT

int main(int argc, char **argv)
{
	(void)argc;
	argv += 1;
	not_buildin(argv);
	if (not_buildin(argv))
	{
		printf("is no build-in\n");
	}
	else
	{
		printf("is build-in \n");
	}
	return (0);
}


#endif