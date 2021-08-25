#include "shell.h"

/**
 * intlen - Determine the number of digit int integer
 * @num: the given number
 *
 * Return: the length of the integer
 */
int intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strcat - concatenates two strings
 * @dest: Destination of the new string
 * @src: Source of the string
 * Return: Return dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j;

	while (*(dest + i))
	{
		i++;
	}
	for (j = 0; *(src + j); j++, i++)
	{
		*(dest + i) = *(src + j);
	}
	*(dest + i) = '\0';
	return (dest);
}
