#include "monty.h"

/**
 * main - encomporates program with extternal arguments
 *
 * @args: number of arguments
 * @argv: argument vectors
 *
 * Return: returns 0 on success, else exit with EXIT FAILURE
 */
int main(int args, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char *buff = NULL;
	ssize_t read_line = 1;
	size_t len = 0;
	unsigned int line = 0;

	if (args != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	built.file = file;
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_line > 0)
	{
		read_line = getline(&buff, &len, file);
		built.content = buff;
		line++;
		if (read_line > 0)
		{
			execute(buff, line, &stack, file);
		}
	}
	free(buff);
	free_list(stack);
	fclose(file);
	return (0);
}
