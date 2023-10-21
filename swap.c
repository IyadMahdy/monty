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
	if (!global.top || !(global.top)->prev)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	s = (global.top)->prev;
	tmp = s->n;
	s->n = (global.top)->n;
	(global.top)->n = tmp;
}
