#include "holberton.h"

/**
 * exit_shell - exits the shell
 *
 * @cmd: data relevant (status and args)
 * Return: 0 on success.
 */
int exit_shell(_unix *cmd)
{
	unsigned int ustatus;
	int is_digit;
	int str_len;
	int big_number;

	if (cmd->args[1] != NULL)
	{
		ustatus = _atoi(cmd->args[1]);
		is_digit = _isdigit(cmd->args[1]);
		str_len = _strlen(cmd->args[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			get_error(cmd, 2);
			cmd->status = 2;
			return (1);
		}
		cmd->status = (ustatus % 256);
	}
	return (0);
}
