#include "holberton.h"

/**
 * _buitins - validates if command is builtin and executes
 * @ssh: input ssh
 * Return: true if found, false if not
 */
_Bool _builtins(_unix *ssh)
{
	register int i = 0;
	cmd Builtins[] = {
		{"exit", _exitsv},
		{"env", _enviroment},
		{"history", _hFunc},
		{"alias", _alias},
		{"cd", _cd},
		{"setenv", setenvFunc},
		{"unsetenv", unsetenvFunc},
		{"help", helpFunc},
		{NULL, NULL}
	};

	while (Builtins[i].command)
	{
		if (_strcmp(ssh->args[0], Builtins[i].command) == 0)
		{
			Builtins[i].func(ssh);
			freeBuffer(ssh);
			return (true);
		}
		i++;
	}
	return (false);
}

/**
 * _exitsv - exits the application
 * @ssh: input ssh
 * Return: 1 on success, 0 on failure
 */
int _exitsv(_unix *ssh)
{
	register int argc, exitstatus;

	argc = Arguments(ssh->args);
	if (argc == 1)
	{
		freeData(ssh);
		if (ssh->errorStatus)
			exit(ssh->errorStatus);
		exit(EXIT_SUCCESS);
	}
	else if (argc > 1)
	{
		exitstatus = _atoi(ssh->args[1]);
		if (exitstatus == -1)
		{
			errno = RALLOC;
			ssh->errorStatus = 2;
			_getError(ssh);
			return (0);
		}
		freeData(ssh);
		exit(exitstatus);
	}
	return (1);
}

/**
 * _hFunc - displays command history
 * @ssh: input ssh
 * Return: 1 on success, 0 on failure
 */
int _hFunc(_unix *ssh)
{
	char *str = "Currently in development\n";

	(void)ssh;
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}

/**
 * _alias - displays local aliases
 * @ssh: input ssh
 * Return: 1 on success, 0 on failure
 */
int _alias(_unix *ssh)
{
	char *str = "Currently in development\n";

	(void)ssh;
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}
