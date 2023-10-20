#include "monty.h"

/**
 * push - Pushes an element to the stack (or queue)
 * @stack: Stack
 * @line_number: Line Number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *s;

	if (!global.data || !int_check())
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	s = malloc(sizeof(stack_t));
	if (!s)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	s->n = atoi(global.data);
	s->next = NULL;
	s->prev = NULL;

	if (global.top)
	{
		(global.top)->next = s;
		s->prev = global.top;
	}
	else
		*stack = s;

	global.top = s;

}

/**
 * int_check - checks if string is an int
 *
 * Return: 0 if not int, 1 if int
 */
int int_check(void)
{
	int i = 0;

	if ((global.data)[0] == '-')
		i++;
	while ((global.data)[i])
	{
		if ((global.data)[i] < 48 || (global.data)[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
