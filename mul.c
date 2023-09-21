#include "monty.h"

/**
 * mul - multiplies the top two elements of the stack_t list
 *
 * @stack: head of the stack_t list
 * @line_number: line number
 *
 * Return: no return value
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int len = 0, mul = 0;
	stack_t *current;

	current = (*stack);
	while (current != NULL)
	{
		current = current->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	mul = (*stack)->n * (*stack)->next->n;
	(*stack)->next->n = mul;

	current = (*stack);
	(*stack) = (*stack)->next;
	if ((*stack) != NULL)
		(*stack)->prev = NULL;
	free(current);
}
