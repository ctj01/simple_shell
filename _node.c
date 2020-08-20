#include "holberton.h"

/**
 * searchNode - searches linked list for string and
 * returns index
 * @head: pointer to head of list
 * @str: input string
 * Return: index of node with matching string
 */
int searchNode(node_l *head, char *str)
{
	register int len = 0, index = 0, i;
	node_l *current;
	char *temporal, *ptr;

	current = head;
	while (current)
	{
		ptr = _strchr(current->string, '=');
		len = ptr - current->string;
		temporal = malloc(sizeof(char) * len + 1);
		for (i = 0; i < len; i++)
			temporal[i] = current->string[i];
		temporal[i] = '\0';
		if (_strcmp(str, temporal) == 0)
		{
			free(temporal);
			return (index);
		}
		index++;
		current = current->next;
		free(temporal);
	}
	return (-1);
}

/**
 * generateLinkedList - generates a linked list of environ
 * variables
 * @array: input array of strings
 * Return: head of linked list
 */
node_l *generateLinkedList(char **array)
{
	register int i = 0;
	node_l *head;

	head = NULL;
	while (array[i])
	{
		addNodeEnd(&head, array[i]);
		i++;
	}
	return (head);
}

/**
 * addNodeAtIndex - add node at index with string
 * @head: double pointer to head
 * @index: index to add at
 * @str: string to add
 * Return: address of node added
 */
node_l *addNodeAtIndex(node_l **head, int index, char *str)
{
	register int i = 0;
	node_l *newNode, *current;
	char *newStr;

	current = *head;
	if (!str)
		return (NULL);
	newNode  = malloc(sizeof(node_l));
	if (!newNode)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	newStr = _strdup(str);
	if (!newStr)
	{
		free(newNode);
		perror("Malloc failed\n");
		exit(errno);
	}

	newNode->string = newStr;
	newNode->next = NULL;

	while (i < index - 1)
	{
		if (current->next == NULL)
		{
			free(newNode);
			return (NULL);
		}
		current = current->next;
		i++;
	}
	newNode->next = current->next;
	current->next = newNode;
	return (newNode);
}

/**
 * getNodeAtIndex - returns the nth node of a listint_t linked list
 * @head: pointer to head of list
 * @index: index of value to be returned
 * Return: address of node at input index
 */
char *getNodeAtIndex(node_l *head, unsigned int index)
{
	register uint count = 0;
	node_l *current;
	char *ptr;

	current = head;
	while (current)
	{
		if (count == index)
		{
			ptr = _strdup(current->string);
			return (ptr);
		}
		count++;
		current = current->next;
	}
	return (NULL);
}
