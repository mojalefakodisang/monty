#include "monty.h"

/**
 * stack_f - switches the flag of struct stack_s list
 *
 * @stack: stack_t list
 * @line_number: line number
 *
 * Return: no return value
 */
void stack_f(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	built.flag = 1;
}

/**
 * queue_f - switches the flag of struct builtint_t
 *
 * @stack: stack_t list
 * @line_number: line number
 *
 * Return: no return value
 */
void queue_f(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	built.flag = 0;
}
