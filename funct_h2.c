#include "shell.h"

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
 * _atoi - Convert a string to an integer
 * @s: string to convert
 *
 * Return: The integer
 */
int _atoi(char *s)
{
	int i, start, negative;
	unsigned int number;

	start = -1;
	negative = 0;
	number = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			start = i;
		if (s[i] == '-' && start == -1)
		{
			if (negative)
				negative = 0;
			else
				negative = 1;
		}
	}
	if (start != -1)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
				number = number * 10 + s[i] - '0';
			else if (s[i - 1] >= '0' && s[i - 1] <= '9')
				break;
		}
	}
	if ((number >= (unsigned int)INT_MAX && negative == 0))
		return (INT_MAX);
	else if ((number > (unsigned int)INT_MAX && negative))
		return (INT_MIN);
	else if (negative)
		return ((int)-number);
	else
		return ((int)number);
}

/**
 * remove_spaces- remove spaces of a string
 * @str:  string to remove spaces
 */

void remove_spaces(char *str)
{
	size_t str_len = _strlen(str);
	char result[512];
	size_t j = 0;
	size_t i = 0;

	for (i = 0; i < str_len; ++i)
	{
		if (str[i] != ' ')
		{
			result[j] = str[i];
			j++;
		}
	}
	if (j < str_len)
		str[j] = '\0';

	for (i = 0; i < j; ++i)
	{
		str[i] = result[i];
	}
}
