#include "monty.h"

/**
 * _mul - Multiplies the top 2 elements
 * @stack: Stack
 * @line_number: Line Number
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	two_elements_check("mul", line_number);

	(global.top)->prev->n = (global.top)->n * (global.top)->prev->n;
	pop(stack, line_number);
}
