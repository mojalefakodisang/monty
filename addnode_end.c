#include "monty.h"

/**
 * addnode_end - adds a new node at the end of list
 *
 * @head: first element of the list
 * @n: data to be added on the list
 *
 * Return: returns the address of the new element else NULL
 */
void addnode_end(stack_t **head, int n)
{
	stack_t *new_node;
	stack_t *last;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		fprintf(stderr, "Error: stack (or queue) list empty");
	last = (*head);

	new_node->n = n;
	new_node->next = NULL;

	if (last)
	{
		while (last->next != NULL)
		{
			last = last->next;
		}
	}
	if (!last)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last->next = new_node;
		new_node->prev = last;
	}
}
