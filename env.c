#include "holberton.h"

/**
 * _enviroment - prints the environment
 * @ssh: input ssh
 * Return: Always 1
 */
int _enviroment(_unix *ssh)
{
	printList(ssh->env);
	return (1);
}

/**
 * setenvFunc - adds env variable if it does not exist;
 * modify env variable if it does
 * @ssh: input ssh
 * Return: Always 1
 */
int setenvFunc(_unix *ssh)
{
	register int index, len;
	static char buffer[BUFSIZE];

	if (Arguments(ssh->args) != 3)
	{
		errno = EWSIZE;
		_getError(ssh);
		return (1);
	}
	len = _strlen(ssh->args[1]) + _strlen(ssh->args[2]) + 2;
	_strcat(buffer, ssh->args[1]);
	_strcat(buffer, "=");
	_strcat(buffer, ssh->args[2]);
	insertNullByte(buffer, len - 1);
	index = searchNode(ssh->env, ssh->args[1]);
	if (index == -1)
	{
		addNodeEnd(&ssh->env, buffer);
		insertNullByte(buffer, 0);
		return (1);
	}
	deleteNodeAtIndex(&ssh->env, index);
	addNodeAtIndex(&ssh->env, index, buffer);
	insertNullByte(buffer, 0);
	return (1);
}

/**
 * unsetenvFunc - deletes env variable if exists;
 * will only accept valid variables names
 * @ssh: input ssh
 * Return: Always 1
 */
int unsetenvFunc(_unix *ssh)
{
	register int _var, i = 1;
	_Bool varfind = false;

	while (ssh->args[i])
	{
		if (_isalpha(ssh->args[i][0]) || ssh->args[i][0] == '_')
		{
			_var = searchNode(ssh->env, ssh->args[i]);
			if (_var > -1)
			{
				deleteNodeAtIndex(&ssh->env, _var);
				varfind = true;
			}
		}
		i++;
	}
	if (varfind == false)
	{
		errno = ENOSTRING;
		_getError(ssh);
	}
	return (1);
}

/**
 * _isalpha - checks if c is an alphabetic character
 * @c: potential alphabetical value
 * Return: if c is a letter, returns 1. Otherwise, return 0.
 */
int _isalpha(int c)
{
	if (c > 64 && c < 91)
		return (1);
	else if (c > 96 && c < 123)
		return (1);
	else
		return (0);
}
