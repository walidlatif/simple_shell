#include "shell.h"

/**
 * _erratoi - Convert a string to an integer.
 * @s: The string to be converted.
 *
 * Return: 0 if there are no numbers in the string
 * otherwise return the converted number,-1 on error.
 */

int _erratoi(char *s)
{
	int i = 0;
	int sign = 1;
	long int result = 0;

	while (s[i] == ' ')
		i++;

	if (s[i] == '+' || s[i] == '-')
	{
		sign = (s[i] == '-') ? -1 : 1;
		i++;
	}

	for (; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result = result * 10 + (s[i] - '0');
			if ((sign == 1 && result > INT_MAX) || (sign == -1 && -result < INT_MIN))
				return (-1);
		}
		else
		{
			return (-1);
		}
	}

	return ((int)(result * sign));
}
/**
 * print_error - Prints an error message.
 * @info: The parameter & return info struct.
 * @estr: String containing the specified error type.
 *
 * Return: 0 if no numbers in the string, converted number otherwise,
 *         -1 on error.
 */

void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}
