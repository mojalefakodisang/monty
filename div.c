#include "monty.h"

/**
 * div_f - divides the top two elements of the stack_t list
 *
 * @stack: head of the stack_t list
 * @line_number: line number
 *
 * Return: no return value
 */
void div_f(stack_t **stack, unsigned int line_number)
{
	int len = 0, div = 1;
	stack_t *current;

	current = (*stack);
	while (current != NULL)
	{
		current = current->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	div = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = div;

	current = *stack;
	(*stack) = (*stack)->next;
	if ((*stack) != NULL)
		(*stack)->prev = NULL;
	free(current);
}
