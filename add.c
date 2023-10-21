#include "monty.h"

/**
 * add - adds the top two elements
 * @stack: Stack
 * @line_number: Line Number
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!(global.top) || !((global.top)->prev))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	 (global.top)->prev->n += (global.top)->n;
	pop(stack, line_number);
}
