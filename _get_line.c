#include "holberton.h"
/**
 * aux_getline -  storing the address of the buf.
 *
 * @lineptr: storing data from buffer
 * @buffer: memory allocated
 * @n: data stream
 * @j: data
 * Return: return the number of characters read
 */
void aux_getline(char **lineptr, size_t *n, char *buffer, size_t j)
{
        if (*lineptr == NULL)
	{
		if  (j > _BUFSIZE)
			*n = j;

		else
			*n = _BUFSIZE;
		*lineptr = buffer;
	}
	else if (*n < j)
	{
		if (j > _BUFSIZE)
			*n = j;
		else
			*n = _BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
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

	int i;
	static ssize_t input;
	ssize_t retval;
	char *buffer;
	char t = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * _BUFSIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= _BUFSIZE)
			buffer = _realloc(buffer, input, input + 1);
		buffer[input] = t;
		input++;
	}
	buffer[input] = '\0';
	aux_getline(lineptr, n, buffer, input);
	retval = input;
	if (i != 0)
		input = 0;
	return (retval);
}
