#include "holberton.h"

/**
 * freeData - frees ssh _unix members
 * @ssh: input ssh
 */
void freeData(_unix *ssh)
{
	if (ssh->env)
		freeList(ssh->env);
	if (ssh->args)
		freeArgs(ssh->args);
	if (ssh->buffer)
		free(ssh->buffer);
}

/**
 * freeBuffer - frees args and buffer
 * @ssh: input ssh
 */
void freeBuffer(_unix *ssh)
{
	freeArgs(ssh->args);
	free(ssh->buffer);
}

/**
 * freeList - frees a linked list
 * @head: double pointer to head of list
 */
void freeList(node_l *head)
{
	node_l *current;
	node_l *tmp;

	if (!head)
		return;
	current = head;
	while (current)
	{
		tmp = current;
		current = tmp->next;
		free(tmp->string);
		free(tmp);
	}
	head = NULL;
}

/**
 * freeArgs - helper func that frees double pointer arg
 * @args: array of char pointers
 */
void freeArgs(char **args)
{
	register uint i = 0;

	while (args[i])
		free(args[i++]);
	free(args);
}
