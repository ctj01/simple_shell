#include "holberton.h"

/**
 * free_ - frees data structure
 *
 * @cmd: data structure
 * Return: no return
 */
void free_(_unix *cmd)
{
	unsigned int i;

	for (i = 0; cmd->_environ[i]; i++)
	{
		free(cmd->_environ[i]);
	}

	free(cmd->_environ);
	free(cmd->pid);
}

/**
 * set_ - Initialize data structure
 *
 * @cmd: data structure
 * @av: argument vector
 * Return: no return
 */
void set_(_unix *cmd, char **av)
{
	unsigned int i;

	cmd->av = av;
	cmd->input = NULL;
	cmd->args = NULL;
	cmd->status = 0;
	cmd->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	cmd->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		cmd->_environ[i] = _strdup(environ[i]);
	}

	cmd->_environ[i] = NULL;
	cmd->pid = _atoiAux(getpid());
}

