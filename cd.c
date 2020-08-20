#include "holberton.h"

/**
 * _cd - execute cd builtin
 * @ssh: input ssh
 * Return: 1 on success, 0 on failure
 */
int _cd(_unix *ssh)
{
	register uint count = 0;
	_Bool ableToChange = false;

	count = Arguments(ssh->args);
	if (count == 1)
		ableToChange = _cdDirectory(ssh);
	else if (count == 2 && _strcmp(ssh->args[1], "-") == 0)
		ableToChange = _cdBefore(ssh);
	else
		ableToChange = _cdUser(ssh);
	if (ableToChange)
		Uenviron(ssh);
	return (1);
}

/**
 * _cdDirectory - change directory to home
 * @ssh: input ssh
 * Return: true on success, false on failure
 */
_Bool _cdDirectory(_unix *ssh)
{
	register int i;
	char *str, *ptr;

	i = searchNode(ssh->env, "HOME");
	if (i == -1)
	{
		return (true);
	}
	str = getNodeAtIndex(ssh->env, i);
	ptr = _strchr(str, '=');
	ptr++;
	chdir(ptr);
	free(str);
	return (true);
}

/**
 * _cdBefore - change directory to previous directory -
 * address is found in OLDPWD env var
 * @ssh: input ssh
 * Return: true on success, false on failure
 */
_Bool _cdBefore(_unix *ssh)
{
	register int i;
	char *str, *ptr;
	char *current = NULL;

	current = getcwd(current, 0);
	i = searchNode(ssh->env, "OLDPWD");
	if (i == -1)
	{
		chdir(current);
		write(STDOUT_FILENO, current, _strlen(current));
		displayNewLine();
		return (true);
	}
	str = getNodeAtIndex(ssh->env, i);
	ptr = _strchr(str, '=');
	ptr++;
	chdir(ptr);
	write(STDOUT_FILENO, ptr, _strlen(ptr));
	displayNewLine();
	free(str);
	return (true);
}

/**
 * _cdUser - change directory to what user inputs in
 * @ssh: input ssh
 * Return: true on success, false on failure
 */
_Bool _cdUser(_unix *ssh)
{
	register int changeStatus;

	changeStatus = chdir(ssh->args[1]);
	if (changeStatus == -1)
	{
		errno = EBADCD;
		_getError(ssh);
		return (false);
	}
	return (true);
}

/**
 * Uenviron - change environmental variables
 * @ssh: input ssh
 * Return: true on success false on failure
 */
_Bool Uenviron(_unix *ssh)
{
	register int i;

	i = uDirectory(ssh);
	current(ssh, i);
	return (true);
}

