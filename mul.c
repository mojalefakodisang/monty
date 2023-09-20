#include "monty.h"
/**
 *mul - multiplies the second top element of the stack with the top element
 *
 *@stack: the head of  a doubly linked list of a stack
 *@line_number: the line number where the instruction appears
 *
 * Return: no return
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int mul;
	int len = 0;

	current = *stack;
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

	mul = (*stack)->next->n * (*stack)->n;
	(*stack)->next->n = mul;

	current = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(current);
}
