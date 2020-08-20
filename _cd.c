#include "holberton.h"

/**
 * uDirectory - updates OLDPWD to current PWD
 * @ssh: input ssh
 * Return: index in linked list of PWD on success -
 * If PWD or OLDPWD does not exist in environ vars,
 * return -1
 */
int uDirectory(_unix *ssh)
{
	register int _pwd = 0, index = 0;
	static char old[BUFSIZE];
	char *current = NULL;

	_strcat(old, "OLD");
	_pwd = searchNode(ssh->env, "PWD");
	if (_pwd == -1)
	{
		return (-1);
	}
	current = getNodeAtIndex(ssh->env, _pwd);
	_strcat(old, current);
	insertNullByte(old, _strlen(current) + 4);
	free(current);
	index = searchNode(ssh->env, "OLDPWD");
	if (index == -1)
	{
		return (-1);
	}
	deleteNodeAtIndex(&ssh->env, index);
	addNodeAtIndex(&ssh->env, index, old);
	insertNullByte(old, 0);
	return (_pwd);
}

/**
 * current - updates PWD to accurately reflect current directory
 * @ssh: input ssh
 * @index: index in linked list of where to insert PWD env var
 * Return: true on success, false on failure
 */
_Bool current(_unix *ssh, int index)
{
	static char tmp[BUFSIZE], cwd[BUFSIZE];

	getcwd(tmp, BUFSIZE);
	_strcat(cwd, "PWD=");
	_strcat(cwd, tmp);
	if (index > -1)
	{
		deleteNodeAtIndex(&ssh->env, index);
		addNodeAtIndex(&ssh->env, index, cwd);
	} else
		addNodeAtIndex(&ssh->env, 0, cwd);
	insertNullByte(tmp, 0);
	insertNullByte(cwd, 0);
	return (true);
}
