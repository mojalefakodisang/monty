#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *stack;
	if (h == NULL)
		return;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
