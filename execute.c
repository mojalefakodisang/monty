#include "monty.h"

/**
 * tokenize - tokenizes input string into an array of strings
 *
 * @content: string to be tokenized
 *
 * Return: an array of strings
 */
char **tokenize(char *content)
{
	char **exec_arg = NULL;
	char *token = NULL;
	int i = 0;

	exec_arg = malloc((strlen(content) / 2 + 2) * sizeof(char *));
	if (exec_arg == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(content, " \n\t");
	while (token != NULL)
	{
		exec_arg[i] = token;
		i++;
		token = strtok(NULL, " \n\t");
	}
	exec_arg[i] = NULL;
	i = 0;

	return (exec_arg);
}

/**
 * execute - gets the opcode function from a opcode keyword
 *
 * @exec_arg: input array of strings
 * @line: line number of the bytecode file
 * @stack: head of the stack_t list
 * @file: bytecode file
 *
 * Return: No return value
 */
void execute(char **exec_arg, unsigned int line, stack_t **stack, FILE *file)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"swap", swap},
		{"nop", nop},
		{NULL, NULL}
	};
	int i = 0, j = 0;
	char *op;

	for (j = 0; exec_arg[j] != NULL; j++)
	{
		op = strtok(exec_arg[j], " \n\t");
		built.arg = exec_arg[j + 1];
		while (ops[i].opcode && op)
		{
			if (strcmp(op, ops[i].opcode) == 0)
			{
				ops[i].f(stack, line);
				return;
			}
			i++;
		}
	}
	if (ops[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, exec_arg[0]);
		fclose(file);
		free_contents(exec_arg);
		exit(EXIT_FAILURE);
	}
}
