#include "shell.h"

/**
 *_strlen- return the length of a string
 *@s: character
 *Return: length os string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		;
	}
	return (i);
}

/**
 *_strcmp-compares the two strings s1 and s2.
 *@s1: string 1 to comparate
 *@s2: string 2 to comparate
 *Return: 1 is success o 0 is fail
 */

int _strcmp(char *s1, char *s2)
{

	int i = 0;


	do {
		if (s1[i] != s2[i])
			return (0);

		i++;
		} while (s1[i]);

	return (1);
}

/**
 * _putstr- prints a string
 * @str: pointer to string
 */

void _putstr(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _strcpy- copies the string pointed to by src,
 * @dest: destnation poiter to take value
 * @src: array poited that gets copied
 * Description: copies string pointed to by src,
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strncat- funtion that concatenate 2 strings
 *@dest: where we appends src
 *@src: the source string to cp
 * Return: cahr
 */

char *_strncat(char *dest, char *src)
{
	int i = 0;
	int j = 0;
	char *copy = malloc(sizeof(char) * 1024);

	if (copy == NULL)
	{
		return (NULL);
	}

	for (i = 0; dest[i] != '\0'; i++)
	{
		copy[i] = dest[i];
	}

	for (j = 0; src[j] != '\0'; j++)
	{
		copy[i + j] = src[j];
	}

	copy[i + j] = '\0';

	return (copy);
}
