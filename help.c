#include "holberton.h"

/**
 * helpFunc - retrieves instruction on how to use builtin
 * @ssh: input ssh
 * Return: Always 1
 */
int helpFunc(_unix *ssh)
{
	cmd _arr[] = {
		{"exit", hExit},
		{"env", hEnv},
		{"history", hHistory},
		{"alias", _Halias},
		{"cd", hCd},
		{"setenv", hSetenv},
		{"unsetenv", hUnsetenv},
		{"help", _Help},
		{NULL, NULL}
	};
	register int i = 0, j = 1, argCount = Arguments(ssh->args);
	_Bool foundCommand = false;

	if (argCount == 1)
		return (displayHelpMenu());
	while (j < argCount)
	{
		i = 0;
		while (_arr[i].command)
		{
			if (_strcmp(ssh->args[j], _arr[i].command) == 0)
			{
				foundCommand = true;
				_arr[i].func(ssh);
				break;
			}
			i++;
		}
		j++;
	}
	if (foundCommand == false)
	{
		errno = ENOBUILTIN;
		_getError(ssh);
	}
	return (1);
}

/**
 * displayHelpMenu - displays available help options
 * Return: Always 1
 */
int displayHelpMenu(void)
{
	char str[81] = "Type help [built-in]\n\nIncluded built-ins:";
	char *str2 = "\n\n\texit\n\tenv\n\tcd\n\tsetenv\n\tunsetenv\n\thelp\n";

	_strcat(str, str2);
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}


/**
 * hExit - instructions on how to exit
 * @ssh: input ssh
 * Return: Always 1
 */
int hExit(_unix *ssh)
{
	char str[82] = "exit: exit [n]\n\tExit the shell.\n\n\t";
	char *str2 = "Exit with a status of n, or if n is omitted, 0.\n";

	(void)ssh;
	_strcat(str, str2);
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}

/**
 * hEnv - instructions on how to exit
 * @ssh: input ssh
 * Return: Always 1
 */
int hEnv(_unix *ssh)
{
	char str[] = "env: env\n\tPrint the environment.\n";

	(void)ssh;
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}

/**
 * hHistory - instructions on how to exit
 * @ssh: input ssh
 * Return: Always 1
 */
int hHistory(_unix *ssh)
{
	char str[] = "history: history\n\tNot supported in this version.\n";

	(void)ssh;
	write(STDOUT_FILENO, str, _strlen(str));
	return (1);
}
