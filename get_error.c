#include "holberton.h"

/**
 * get_error - calls the error according the builtin, syntax or permission
 * @cmd: data structure that contains arguments
 * @eval: error value
 * Return: error
 */
int get_error(_unix *cmd, int eval)
{
	char *error;

	switch (eval)
	{
	case -1:
		error = error_env(cmd);
		break;
	case 126:
		error = error_path_126(cmd);
		break;
	case 127:
		error = error_not_found(cmd);
		break;
	case 2:
		if (_strcmp("exit", cmd->args[0]) == 0)
			error = error_exit_shell(cmd);
		else if (_strcmp("cd", cmd->args[0]) == 0)
			error = error_get_cd(cmd);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	cmd->status = eval;
	return (eval);
}
