#include "holberton.h"
/**
 * aux_getline -  storing the address of the buf.
 *
 * @lineptr: storing data from buffer
 * @n : memory allocated
 * @stream: data stream
 * Return: return the number of characters read
 */
ssize_t aux_getline(char **lineptr, size_t *n, FILE *stream)
{
	const size_t _REALLOCMEMORY = 1024;
	int c;
	size_t n_read = 0;

	while (EOF != (c = getc(stream)))
	{
		n_read++;
		if (n_read >= *n)
		{
			size_t n_realloc = *n + _REALLOCMEMORY;
			char *tmp = realloc(*lineptr, n_realloc + 1);

			if (tmp != NULL)
			{
				*lineptr = tmp;
				*n = n_realloc;
			}
			else
			{

				return (-1);
			}

			if (*n > SSIZE_MAX)
				return (-1);

		}

		(*lineptr)[n_read - 1] = (char) c;

		if (c == '\n')
			break;
	}

	if (c == EOF)
		return (-1);
	(*lineptr)[n_read] = '\0';

	return ((ssize_t) n_read);
}
/**
 * _getline - reads an entire line from stream.
 *
 * @lineptr: storing data from buffer
 * @n : memory allocated
 * @stream: data stream
 * Return: return the number of characters read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	const size_t INITIAL_MEMORY = 1024;


	if ((!*lineptr) || (!n) || (!stream))
	{
		errno = EINVAL;
		return (-1);
	}

	if (*lineptr == NULL)
	{
		*lineptr = malloc(INITIAL_MEMORY);
		if (!*lineptr)
		{
			return (-1);
		}
		else
		{
			*n = INITIAL_MEMORY;
		}
	}

	return (aux_getline(*(&lineptr), n, stream));
}
