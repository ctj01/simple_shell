#include "holberton.h"

/**
 * splitString - splits string into an array of strings
 * separated by spaces
 * @ssh: input ssh
 * Return: true if able to split, false if not
 */
_Bool splitString(_unix *ssh)
{
	register unsigned int i = 0;
	char *tok, *cpy;

	if (countWords(ssh->buffer) == 0)
	{
		ssh->args = NULL;
		free(ssh->buffer);
		return (false);
	}
	ssh->args = malloc((countWords(ssh->buffer) + 1) * sizeof(char *));
	cpy = _strdup(ssh->buffer);
	tok = _strtok(cpy, " ");
	while (tok)
	{
		ssh->args[i] = _strdup(tok);
		tok = _strtok(NULL, " ");
		i++;
	}
	ssh->args[i] = NULL;
	free(cpy);
	return (true);
}

/**
 * countWords - count number of words in a string
 * @str: input string
 * Return: number of words
 */
unsigned int countWords(char *str)
{
	register int words = 0;
	_Bool wordOn = false;

	while (*str)
	{
		if (isSpace(*str) && wordOn)
			wordOn = false;
		else if (!isSpace(*str) && !wordOn)
		{
			wordOn = true;
			words++;
		}
		str++;
	}
	return (words);
}

/**
 * isSpace - determines if char is a space
 * @c: input char
 * Return: true or false
 */
_Bool isSpace(char c)
{
	return (c == ' ');
}
