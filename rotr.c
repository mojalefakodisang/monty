#include "monty.h"
/**
 *rotr - rotates the stack to the bottom
 *
 *@stack: the head of  a doubly linked list of a stack
 *@line_number: the line number where the instruction appears
 *
 * Return: no return
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = *stack;
	current->prev->next = NULL;
	current->prev = NULL;
	(*stack)->prev = current;
	*stack = current;
}
