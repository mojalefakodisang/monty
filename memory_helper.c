#include "monty.h"

/**
 * free_contents - frees contents of the array of strings
 *
 * @exec_arg: input array of strings
 *
 * Return: no return value
 */
void free_contents(char **exec_arg)
{
	int count = 0;

	while (exec_arg[count] != NULL)
	{
		free(exec_arg[count]);
		count++;
	}
	free(exec_arg);
}

/**
 * free_list - frees the stack_t list
 *
 * @head: top of the stack_t list
 *
 * Return: no return value
 */
void free_list(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
