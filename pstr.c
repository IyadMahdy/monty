#include "monty.h"

/**
 * pstr - Prints string starting from top
 * @stack: Stack
 * @line_number: Line Number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *s;

	(void) stack;
	(void) line_number;
	s = global.top;
	while (s && s->n && s->n >= 0 && s->n <= 127)
	{
		printf("%c", s->n);
		s = s->prev;
	}
	printf("\n");
}
