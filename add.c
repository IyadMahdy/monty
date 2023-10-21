#include "monty.h"

/**
 * add - adds the top two elements
 * @stack: Stack
 * @line_number: Line Number
 */
void add(stack_t **stack, unsigned int line_number)
{
	two_elements_check("add", line_number);
	(global.top)->prev->n += (global.top)->n;
	pop(stack, line_number);
}
