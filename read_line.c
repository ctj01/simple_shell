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

	input = malloc(_BUFSIZE);
	if (!input)
	{
		free(input);
		return (NULL);
	}

	*_EOF = _getline(&input, &bufsize, stdin);

	return (input);
}
