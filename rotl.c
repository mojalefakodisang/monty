#include "monty.h"
/**
 *rotl - rotates the stack to the top
 *
 *@stack: the head of  a doubly linked list of a stack
 *@line_number: the line number where the instruction appears
 *
 * Return: no return
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *new_stack;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	new_stack = (*stack)->next;
	new_stack->prev = NULL;
	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = (*stack);
	(*stack)->next = NULL;
	(*stack)->prev = current;
	*stack = new_stack;
}
