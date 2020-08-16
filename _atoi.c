#include "holberton.h"

/**
 * _len - Get the lenght of a number.
 * @n: type int number.
 * Return: Lenght of a number.
 */
int _len(int n)
{
	unsigned int number;
	int lenght = 1;

	if (n < 0)
	{
		lenght++;
		number = n * -1;
	}
	else
	{
		number = n;
	}
	while (number > 9)
	{
		lenght++;
		number = number / 10;
	}

	return (lenght);
}
/**
 * _atoiAux - function converts int to string.
 * @n: type int number
 * Return: String.
 */
char *_atoiAux(int n)
{
	unsigned int number;
	int lenght = _len(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (lenght + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + lenght) = '\0';

	if (n < 0)
	{
		number = n * -1;
		buffer[0] = '-';
	}
	else
	{
		number = n;
	}

	lenght--;
	do {
		*(buffer + lenght) = (number % 10) + '0';
		number = number / 10;
		lenght--;
	}
	while (number > 0)
		;
	return (buffer);
}

/**
 * _atoi - converts a string to an integer.
 * @string: input string.
 * Return: integer.
 */
int _atoi(char *string)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(string + count) != '\0')
	{
		if (size > 0 && (*(string + count) < '0' || *(string + count) > '9'))
			break;

		if (*(string + count) == '-')
			pn *= -1;

		if ((*(string + count) >= '0') && (*(string + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(string + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
