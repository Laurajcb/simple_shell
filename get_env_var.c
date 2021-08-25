#include "shell.h"

/**
 * get_env_var-function to get the value of the respective key in the ENVIRONS
 * @var_name:is the key that we'll be search
 * key: is the name of the current var
 * value:is the value of the environment key
 * current_env: where we are looking the key
 * Return: NULL if didn't found the key otherewise the value
 */

char *get_env_var(char *var_name, int count, char *tokens)
{
	int i = 0;
	char *current_env = NULL;
	int size = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (grepVariable(environ[i], var_name))
		{
			size = _strlen(environ[i]) - _strlen(var_name);
			current_env = malloc(sizeof(char) * size + 1);
			_strcpy(current_env, environ[i] + _strlen(var_name));
			
			if (access(current_env, F_OK) == -1)
			{
				d_printf(STDERR_FILENO, "%d: %s: not found\n", count - 1, tokens);
			}
			return (current_env);
		}
	}
	return (NULL);

}
