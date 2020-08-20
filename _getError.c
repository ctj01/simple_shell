#include "holberton.h"

/**
 * _getError - prints error message for shell
 * @ssh: the ssh _unix
 */
void _getError(_unix *ssh)
{
	register int len;
	static char error[BUFSIZE];
	char *ptr, *alpha;

	alpha = itoa(ssh->lineCounter);
	_strcat(error, ssh->shellName);
	_strcat(error, ": ");
	_strcat(error, alpha);
	_strcat(error, ": ");
	_strcat(error, ssh->args[0]);
	_strcat(error, OutError());
	if (ssh->args[1])
	{
		if (errno != HCD)
			_strcat(error, ": ");
		_strcat(error, ssh->args[1]);
	}
	_strcat(error, "\n");
	ptr = _strchr(error, '\n');
	len = ptr - error;
	write(STDERR_FILENO, error, len + 1);
	free(alpha);
	insertNullByte(error, 0);
}

/**
 * OutError - matches errno to corresponding string
 * Return: string of error message
 */
char *OutError(void)
{
	char *str;

	switch (errno)
	{
		case HCD:
			str = ": can't cd to ";
			break;
		case ENOENT:
			str = ": not found";
			break;
		case ENO:
			str = ": bad variable name";
			break;
		case RALLOC:
			str = ": Illegal number";
			break;
		case ESIZE:
			str = ": invalid number of arguments";
			break;
		case EBUILT:
			str = ": type help for a list of built-ins";
			break;
		case EACCES:
			str = ": Permission denied";
			break;
		default:
			str = ": no error number assigned";
	}
	return (str);
}

/**
 * countDigits - count number of digits in a number
 * @num: input number
 * Return: number of digits
 */
unsigned int countDigits(int num)
{
	register int digits = 0;

	while (num > 0)
	{
		digits++;
		num /= 10;
	}
	return (digits);
}

/**
 * itoa - converts integer to string
 * @num: input integer
 * Return: string type of number
 */
char *itoa(unsigned int num)
{
	register int digits = 0;
	char *str;

	digits += countDigits(num);
	str = malloc(sizeof(char) * (digits + 1));
	if (!str)
	{
		perror("Malloc: failed\n");
		exit(errno);
	}
	insertNullByte(str, digits);
	while (num > 0)
	{
		str[digits - 1] = num % 10 + '0';
		num = num / 10;
		digits--;
	}
	return (str);
}
