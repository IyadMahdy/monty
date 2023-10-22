#include "monty.h"

/**
 * sub - Subtracts the top two elements
 * @stack: Stack
 * @line_number: Number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int res;

	two_elements_check("sub", line_number);

	res = (global.top)->n;
	pop(stack, line_number);
	global.top->n = res - global.top->n;
}
