#include "holberton.h"

/**
 * add_rvar_node - adds a variable at the end
 * of a _var list.
 * @head: head of the linked list.
 * @lvar: length of the variable.
 * @val: value of the variable.
 * @lval: length of the value.
 * Return: address of the head.
 */
_var *add_rvar_node(_var **head, int lvar, char *val, int lval)
{
	_var *new, *temp;

	new = malloc(sizeof(_var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->_val = lval;

	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_rvar_list - frees a _var list
 * @head: head of the linked list.
 * Return: no return.
 */
void free_rvar_list(_var **head)
{
	_var *temp;
	_var *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
