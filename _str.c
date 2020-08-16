#include "holberton.h"

/**
 * _strdup - duplicates a str in the heap memory.
 * @s: Type char pointer str
 * Return: duplicated str
 */
char *_strdup(const char *s)
{
	char *new;
	size_t len;

	len = _strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, len + 1);
	return (new);
}

/**
 * _strlen - Returns the lenght of a string.
 * @s: Type char pointer
 * Return: Always 0.
 */
int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmp_chars - compare chars of strings
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * _strtok - splits a string by some delimiter.
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: string splited.
 */
char *_strtok(char str[], const char *delim)
{
	static char *sp, *str_e;
	char *str_i;
	unsigned int i, del;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		sp = str;
		i = _strlen(str);
		str_e = &str[i];
	}
	str_i = sp;
	if (str_i == str_e)
		return (NULL);

	for (del = 0; *sp; sp++)
	{
		if (sp != str_i)
			if (*sp && *(sp - 1) == '\0')
				break;
		for (i = 0; delim[i]; i++)
		{
			if (*sp == delim[i])
			{
				*sp = '\0';
				if (sp == str_i)
					str_i++;
				break;
			}
		}
		if (del == 0 && *sp) 
			del = 1;
	}
	if (del == 0)
		return (NULL);
	return (str_i);
}

/**
 * _isdigit - defines if string passed is a number
 *
 * @s: input string
 * Return: 1 if string is a number. 0 in other case.
 */
int _isdigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}