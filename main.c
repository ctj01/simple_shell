#include "holberton.h"

/**
 * main - entry point for application
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	_unix ssh;

	(void)ac;
	signal(SIGINT, sigintHandler);
	configInit(&ssh);
	ssh.shellName = av[0];
	shell(&ssh);
	return (0);
}

/**
 * configInit - initialize member values for _unix struct
 * @ssh: input ssh
 * Return: ssh with initialized members
 */
_unix *configInit(_unix *ssh)
{
	ssh->env = generateLinkedList(environ);
	ssh->envList = NULL;
	ssh->args = NULL;
	ssh->buffer = NULL;
	ssh->path = _getenv("PATH", environ);
	ssh->fullPath = NULL;
	ssh->lineCounter = 0;
	ssh->shellName = NULL;
	ssh->errorStatus = 0;
	return (ssh);
}
