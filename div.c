#include "monty.h"

/**
 * _div - Divides the top two elements
 * @stack: Stack
 * @line_number: Line Number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	two_elements_check("div", line_number);

	if ((global.top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	(global.top)->prev->n /= (global.top)->n;
	pop(stack, line_number);
}
