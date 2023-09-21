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
	if (h == NULL)
	{
		printf("\n");
	}
	if (h->n >= 0 && h->n <= 127)
	{
		while (h != NULL && h->n != 0)
		{
			printf("%c", (char)h->n);
			h = h->next;
		}
		printf("\n");
	}
}
