#include "shell.h"
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

/**
 * d_printf - ?
 * @format:  string to remove spaces
 * @fd:  string to remove spaces
 * Return: ?
 */
int d_printf(int fd, const char *format, ...)
{
	char str_to_print[1024], number_toprint[24];
	char *str = NULL, *buff = NULL;
	int number = 0;
	va_list args;

	va_start(args, format);
	buff = str_to_print;

	while (*format)
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				for (str = va_arg(args, char *); *str;)
					*buff++ = *str++;
			else if (*format == 'd' || *format == 'i')
			{
				number = va_arg(args, int);
				int_to_str(number, number_toprint);
				for (str = number_toprint; *str;)
					*buff++ = *str++;
			}
			format++;
		}
		else
			*buff++ = *format++;
	*buff = '\0';
	va_end(args);
	write(fd, str_to_print, buff - (char *)str_to_print);
	return (buff - (char *)str_to_print);
}

/**
 * int_to_str - function that convert a int to string
 * @x: integer to convert to string
 * @str: array that containt string result
 * Return: length string result
 * On error, return 0
 */
int int_to_str(int x, char str[])
{
	int i = 0;

	if (x == INT_MIN)
	{
		str[0] = '0';
		str[1] = '2';
		str[2] = '1';
		str[3] = '4';
		str[4] = '7';
		str[5] = '4';
		str[6] = '8';
		str[7] = '3';
		str[8] = '6';
		str[9] = '4';
		str[10] = '8';
		str[11] = '\0';
		return (11);
	}
	if (x < 0)
	{
		x = (x * -1);
		str[i] = '-';
		i++;
	}
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	reverse(str, i);
	str[i] = '\0';
	if (i == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	return (i);
}

/**
 * reverse - function that reverse a string
 * @str: string to reverse
 * @len: len of string
 * Return: int number of characters
 * On error, return 0
 */

void reverse(char *str, int len)
{
	int i = 0, j = len - 1, temp;

	if (str[i] == '-')
		i++;

	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

/**
 * grepVariable - ? functionjajsjc
 * @variable_env: ?
 * @var_name: ?
 * Return: ?
 */
int grepVariable(char *variable_env, char *var_name)
{
	int i = 0;

	if (variable_env == NULL || var_name == NULL)
		return (0);

	for (i = 0; var_name[i]; i++)
	{
		if (variable_env[i] != var_name[i])
			break;
	}
	return (var_name[i] == '\0');
}
