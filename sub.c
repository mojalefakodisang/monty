#include "monty.h"

/**
 * sub - subtracts the top two elements of the stack_t list
 *
 * @stack: head of the stack_t list
 * @line_number: line number
 *
 * Return: no return value
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int len = 0, sub = 0;
	stack_t *current = (*stack);

	while (current != NULL)
	{
		current = current->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = sub;

	current = *stack;
	(*stack) = (*stack)->next;
	if ((*stack) != NULL)
		(*stack)->prev = NULL;
	free(current);
}
