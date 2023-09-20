#include "monty.h"

/**
 * add - adds the two top nodes from the stack_t list
 *
 * @stack: stack_t list head
 * @line_number: number of the line in the bytecode file
 *
 * Return: No return value
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int sum;
	int len = 0;

	current = *stack;
	while (current != NULL)
	{
		current = current->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;

	current = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(current);
}
