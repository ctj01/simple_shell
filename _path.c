#include "holberton.h"

/**
 * pathChecker - searches $PATH for directory of command
 * @ssh: input ssh
 * Return: true if command found
 */
_Bool pathChecker(_unix *ssh)
{
	register int len;
	static char buffer[BUFSIZE];
	struct stat st;
	char *tok, *copy, *delim = ":", *tmp;
	_Bool inLoop = false;

	if (_eCases(ssh))
		return (true);
	copy = _strdup(ssh->path);
	tok = _strtok(copy, delim);
	while (tok)
	{
		tmp = inLoop ? tok - 2 : tok;
		if (*tmp == 0 && stat(ssh->args[0], &st) == 0)
		{
			ssh->fullPath = ssh->args[0];
			free(copy);
			return (true);
		}
		len = _strlen(tok) + _strlen(ssh->args[0]) + 2;
		_strcat(buffer, tok);
		_strcat(buffer, "/");
		_strcat(buffer, ssh->args[0]);
		insertNullByte(buffer, len - 1);
		if (stat(buffer, &st) == 0)
		{
			free(copy);
			ssh->fullPath = buffer;
			return (true);
		}
		insertNullByte(buffer, 0);
		tok = _strtok(NULL, delim);
		inLoop = true;
	}
	ssh->fullPath = ssh->args[0];
	free(copy);
	return (false);
}

/**
 * _eCases - helper func for check path to check edge cases
 * @ssh: input ssh
 * Return: true if found, false if not
 */
_Bool _eCases(_unix *ssh)
{
	char *copy;
	struct stat st;

	copy = _strdup(ssh->path);
	if (!copy)
	{
		ssh->fullPath = ssh->args[0];
		free(copy);
		return (true);
	}
	if (*copy == ':' && stat(ssh->args[0], &st) == 0)
	{
		ssh->fullPath = ssh->args[0];
		free(copy);
		return (true);
	}
	free(copy);
	return (false);
}
