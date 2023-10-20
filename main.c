#include "monty.h"
#include <stdio.h>

globals global = {NULL, NULL};

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
	char *opcode;
	unsigned int line_number = 0;
	instruction_t opcodes[] = {
		{"push", push}, {"pall", pall}, {NULL, NULL}
	};
	stack_t *s;
	int i = 0;

	argc_check(argc);
	fp = fopen(argv[1], "r");
	file_check(fp, argv[1]);
	while (fgets(buffer, BUFF_SIZE, fp))
	{
		line_number++;
		opcode = strtok(buffer, " \n\t");
		if (!opcode)
			continue;
		for (i = 0; i < OPCODE_COUNT; i++)
		{
			if (!(opcodes[i].opcode) || !opcode)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				free_stack();
				exit(EXIT_FAILURE);
			}
			if (strcmp(opcode, opcodes[i].opcode) == 0)
			{
				if (i == 0)
					global.data = strtok(NULL, " \t\n");
				opcodes[i].f(&s, line_number);
				break;
			}
		}
	}
	fclose(fp);
	free_stack();
	return (0);
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
