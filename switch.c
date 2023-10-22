#include "monty.h"

/**
 * to_stack - sets format to stack
 * @stack: Stack
 * @line_number: Line Number
 */
void to_stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	global.mode = STACK;
}

/**
 * to_queue - sets format to queue
 * @stack: Stack
 * @line_number: Line Number
 */
void to_queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	global.mode = QUEUE;
}
