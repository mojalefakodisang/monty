#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{	
	stack_t *current;
	int temp;
	int len = 0;

	current = *stack;
	while (current != NULL)
	{
		current = current->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
