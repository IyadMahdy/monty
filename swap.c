#include "monty.h"

/**
 * swap - Swap the 2 top elements
 * @stack: Pointer to stack
 * @line_number: Line Number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *s;
	int tmp;

	(void) stack;
	two_elements_check("swap", line_number);

	s = (global.top)->prev;
	tmp = s->n;
	s->n = (global.top)->n;
	(global.top)->n = tmp;
}
