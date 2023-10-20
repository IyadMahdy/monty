#include "monty.h"

/**
 * get_top - Gets top of stack (or queue)
 * @stack: Pointer to stack (or queue)
 */
void get_top(stack_t **stack)
{
	stack_t *s;

	s = *stack;
	if (!s)
	{
		global.top = NULL;
		return;
	}
	while (s->next)
		s = s->next;
	global.top = s;
}
