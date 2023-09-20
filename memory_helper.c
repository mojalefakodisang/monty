#include "monty.h"

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
