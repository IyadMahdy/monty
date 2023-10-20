#include "monty.h"

/**
 * pop - Removes top element
 * @stack: Stack
 * @line_number: Line Number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *s;

	(void) stack;
	if (!global.top)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	s = global.top;
	global.top = (global.top)->prev;
	(global.top)->next = NULL;
	free(s);
}
