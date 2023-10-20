#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: Pointer to stack
 * @line_number: Line Number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (!global.top)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (global.top)->n);
}
