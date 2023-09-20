#include "monty.h"

void addnode(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Malloc failed");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = (*head);
	new_node->prev = NULL;

	if ((*head) != NULL)
	{
		(*head)->prev = new_node;
	}
	(*head) = new_node;
}
