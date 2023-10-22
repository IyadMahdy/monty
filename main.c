#include "monty.h"

globals global = {NULL, NULL, STACK};

/**
 * main - interpreter for Monty ByteCodes files.
 * @argc: Argument Count
 * @argv: Array of arguments
 *
 * Return: 0 if successful
 */
int main(int argc, char **argv)
{
	FILE *fp;
	char buffer[BUFF_SIZE];
	stack_t *s = NULL;
	unsigned int line_number = 0;

	argc_check(argc);
	fp = fopen(argv[1], "r");
	file_check(fp, argv[1]);
	while (fgets(buffer, BUFF_SIZE, fp))
	{
		line_number++;
		run(&s, buffer, line_number);
	}
	fclose(fp);
	free_stack();
	return (0);
}

/**
 * run - Runs the interpreter
 * @stack: Stack
 * @buffer: Buffer that stores the line
 * @line_number: Line Number
 */
void run(stack_t **stack, char buffer[], unsigned int line_number)
{
	unsigned int i = 0;
	char *opcode;
	instruction_t opcodes[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub}, {"mul", _mul},
		{"div", _div}, {"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr},
		{"stack", to_stack}, {"queue", to_queue}, {NULL, NULL}
	};

	opcode = strtok(buffer, " \n\t");
	if (!opcode || opcode[0] == '#')
		return;
	while (1)
	{
		if (!(opcodes[i].opcode))
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			free_stack();
			exit(EXIT_FAILURE);
		}
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			if (i == 0)
				global.data = strtok(NULL, " \t\n");
			opcodes[i].f(stack, line_number);
			break;
		}
		i++;
	}
}

/**
 * file_check - Checks if file exists
 * @fp: File pointer
 * @file: File name
 */
void file_check(FILE *fp, char *file)
{
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		free_stack();
		exit(EXIT_FAILURE);
	}
}

/**
 * argc_check - Checks if valid argument count
 * @argc: Argument Count
 */
void argc_check(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free_stack();
		exit(EXIT_FAILURE);
	}
}
