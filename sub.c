#include "monty.h"

/**
 * sub - Subtracts the top two elements
 * @stack: Stack
 * @line_number: Number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	two_elements_check("sub", line_number);

	(global.top)->prev->n = (global.top)->n - (global.top)->prev->n;
	pop(stack, line_number);
}
