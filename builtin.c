#include "holberton.h"

/**
* Arguments - count the number of arguments
* @args: input array of strings
* Return: number of strings
*/
int Arguments(char **args)
{
	register int i = 0;

	while (args[i])
		i++;
	return (i);
}

/**
* _atoi - change string to an integer
* @string: input string
* Return: -1 if it'string not a valid number, else the converted number
*/
int _atoi(char *string)
{
	register int i = 0;
	unsigned long number = 0;

	while (string[i])
	{
		if (string[i] >= '0' && string[i] <= '9')
			number = number * 10 + string[i] - '0';
		else
			return (-1);
		i++;
	}
	if (number > INT_MAX)
	{
		return (-1);
	}
	return (number);
}
