#include "monty.h"

/**
 * rotr - Makes the last element of the list the top
 * @stack: Stack
 * @line_number: Line Number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if (!global.top || !global.top->prev)
		return;

	(*stack)->prev = global.top;
	global.top->next = (*stack);
	*stack = (*stack)->next;
	global.top = global.top->next;
	global.top->next = NULL;
	(*stack)->prev = NULL;
}
