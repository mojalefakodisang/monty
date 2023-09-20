#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (built.arg != NULL)
	{
		for (; built.arg[j] != '\0'; j++)
		{
			if (built.arg[j] == '-')
				j++;
			if (built.arg[j] < 48 || built.arg[j] > 57)
			{
				flag = 1;
			}
			if (flag == 1)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				fclose(built.file);
				free(built.content);
				free_list(*stack);
				exit(EXIT_FAILURE);
			}
		}
		n = atoi(built.arg);
		addnode(stack, n);
	}
}
