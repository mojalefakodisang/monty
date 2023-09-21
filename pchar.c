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
	char c;

	h = *stack;
	if (h == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(built.file);
		free(built.content);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	if ((h->n >= 0 && h->n <= 127))
	{
		c = (char)h->n;
		printf("%c\n", c);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(built.file);
		free(built.content);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
}
