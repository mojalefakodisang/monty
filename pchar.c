#include "monty.h"
/**
 *pchar - prints the char at the top of the stack
 *
 *@stack: the head of  a doubly linked list of a stack
 *@line_number: the line number where the instruction appears
 *
 * Return: no return
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	h = *stack;
	if (h == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((h->n >= 65 && h->n <= 90) || (h->n >= 97 && h->n <= 122))
	{
		printf("%c\n", (char)h->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}