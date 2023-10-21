#include "monty.h"

/**
 * sub - Subtracts the top two elements
 * @stack: Stack
 * @line_number: Number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (!(global.top) || !((global.top)->prev))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	(global.top)->prev->n = (global.top)->n - (global.top)->prev->n;
	pop(stack, line_number);
}
