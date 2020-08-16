#include "holberton.h"

/**
 * exec_line - finds builtins and commands
 *
 * @cmd: data relevant (args)
 * Return: 1 on success.
 */
int exec_line(_unix *cmd)
{
	int (*_command)(_unix *cmd);

	if (cmd->args[0] == NULL)
		return (1);

	_command = _build_command(cmd->args[0]);

	if (_command != NULL)
		return (_command(cmd));

	return (cmd_exec(cmd));
}
