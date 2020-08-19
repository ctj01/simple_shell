#include "holberton.h"
/**
 * main - Entry point
 *
 * @ac: argument count
 * @argv: argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **argv)
{
	_unix cmd;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_(&cmd, argv);
	shell_(&cmd);
	free_(&cmd);
	if (cmd.status < 0)
		return (EXIT_FAILURE);
	return (cmd.status);
}
