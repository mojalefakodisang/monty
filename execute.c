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
 * @buff: input array of strings
 * @line: line number of the bytecode file
 * @stack: head of the stack_t list
 * @file: bytecode file
 *
 * Return: No return value
 */
int execute(char *buff, unsigned int line, stack_t **stack, FILE *file)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"swap", swap},
		{"nop", nop},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};
	int i = 0;
	char *op;

	op = strtok(buff, " \n\t");
	if (op && op[0] == '#')
		return (0);

	built.arg = strtok(NULL, " \n\t");
	while (ops[i].opcode && op)
	{
		if (strcmp(op, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line);
			return (0);
		}
		i++;
	}
	if (op && ops[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, op);
		fclose(file);
		free(buff);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
