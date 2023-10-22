#include "monty.h"

/**
 * rotl - Makes the top element of the list the first
 * @stack: Stack
 * @line_number: Line Number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if (!global.top || !global.top->prev)
		return;

	global.top->next = (*stack);
	(*stack)->prev = global.top;
	*stack = global.top;
	global.top = global.top->prev;
	global.top->next = NULL;
	(*stack)->prev = NULL;
}
