#ifndef MONTY_H_
#define MONTY_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Structures */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct builtint_s
{
	char *content;
	char *arg;
	FILE *file;
} builtint_t;

extern builtint_t built;

/* Main functions */

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/* Helper functions */

char **tokenize(char *content);
void free_contents(char **exec_arg);
void free_list(stack_t *head);
void execute(char **exec_arg, unsigned int line, stack_t **stack, FILE *file);
void addnode(stack_t **head, int n);

#endif
