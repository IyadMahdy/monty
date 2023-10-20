#include "monty.h"

/**
 * pall - Prints all values of stack starting from top
 * @stack: Pointer to stack
 * @line_number: Line Number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *s;

	(void) stack;
	(void) line_number;
	s = global.top;

	if (!s)
		return;
	while (s->prev)
	{
		printf("%d\n", s->n);
		s = s->prev;
	}
	printf("%d\n", s->n);
}
