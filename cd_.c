#include "holberton.h"

/**
 * cd_shell - changes current directory
 *
 * @cmd: data relevant
 * Return: 1 on success
 */
int cd_shell(_unix *cmd)
{
	char *dir;
	int home, home_, _datas;

	dir = cmd->args[1];

	if (dir != NULL)
	{
		home = _strcmp("$HOME", dir);
		home_ = _strcmp("~", dir);
		_datas = _strcmp("--", dir);
	}

	if (dir == NULL || !home || !home_ || !_datas)
	{
		cd_to_home(cmd);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		cd_previous(cmd);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd_dot(cmd);
		return (1);
	}

	cd_to(cmd);

	return (1);
}
