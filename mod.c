#include "monty.h"

/**
 * mod - modulos of the top two elements of the list
 *
 * @stack: head of stack_t list
 * @line_number: line number
 *
 * Return: no return values
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int len = 0, mod = 1;
	stack_t *current;

	current = (*stack);
	while (current != NULL)
	{
		current = current->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	mod = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = mod;
	current = (*stack);
	(*stack) = (*stack)->next;
	if ((*stack) != NULL)
		(*stack)->prev = NULL;
	free(current);
}
