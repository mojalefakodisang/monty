#include "monty.h"
/**
 *pstr - prints the string at the top of the stack
 *
 *@stack: the head of  a doubly linked list of a stack
 *@line_number: the line number where the instruction appears
 *
 * Return: no return
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *stack;
	while (h && h != NULL)
	{
		if (h->n <= 0 || h->n > 127)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
