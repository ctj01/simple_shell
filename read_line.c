#include "holberton.h"

/**
 * read_line - reads the input string.
 *
 * @_EOF: return value of getline function
 * Return: input string
 */
char *read_line(int *_EOF)
{
	char *input = NULL;
	size_t bufsize = 0;

	*_EOF = getline(&input, &bufsize, stdin);
	return (input);
}
