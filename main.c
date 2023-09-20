#include "monty.h"
builtint_t built = {NULL, NULL, NULL};

int main(int args, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char *buff = NULL, **exec_arg = NULL;
	ssize_t read_line = 1;
	size_t len = 0;
	unsigned int line = 1;

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
	else
	{
		while (read_line > 0)
		{
			read_line = getline(&buff, &len, file);
			built.content = buff;
			if (read_line > 0)
			{
				exec_arg = tokenize(buff);
				execute(exec_arg, line, &stack, file);
				line++;
			}
		}
	}
	free(buff);
	fclose(file);
	return (0);
}
