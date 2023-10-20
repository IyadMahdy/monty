#include "monty.h"

/**
 * free_stack - frees a stack
 */
void free_stack(void)
{
	stack_t *s;

	while (global.top)
	{
		s = global.top;
		global.top = (global.top)->prev;
		free(s);
	}
}

/**
 * free_globals - frees globals
 */
void free_globals(void)
{
}
