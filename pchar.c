#include "monty.h"

/**
 * pchar - Prints the char at the top of the stack
 * @stack: Stack
 * @line_number: Line Number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (global.top->n < 0 || global.top->n > 127 || !(global.top))
	{
		if (!(global.top))
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		else
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);

		free_stack();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", global.top->n);
}
