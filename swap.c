#include "monty.h"

/**
 * swap - Swap the 2 top elements
 * @stack: Pointer to stack
 * @line_number: Line Number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (!global.top || !(global.top)->prev || !(global.top)->prev->prev)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	(global.top)->prev->next = NULL;
	(global.top)->next = (global.top)->prev;
	(global.top)->prev = (global.top)->prev->prev;
	(global.top)->prev->prev = global.top;
	(global.top)->prev->prev->next = global.top;
	global.top = (global.top)->next;
}
