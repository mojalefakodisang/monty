#include "monty.h"
/**
 *sub - subtracts the top element of the stack from the second
 *
 *@stack: the head of  a doubly linked list of a stack
 *@line_number: the line number where the instruction appears
 *
 * Return: no return
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int sub;
	int len = 0;

	current = *stack;
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
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(current);
}
