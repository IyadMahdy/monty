#include "monty.h"

/**
 * push - Pushes an element to the stack (or queue)
 * @stack: Stack
 * @line_number: Line Number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (!global.data || !int_check())
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack();
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(global.data);
	new_node->next = NULL;
	new_node->prev = NULL;
	if (global.mode == STACK)
	{
		if (global.top)
		{
			(global.top)->next = new_node;
			new_node->prev = global.top;
		}
		else
			*stack = new_node;

		global.top = new_node;
	}
	else
	{
		if (*stack == NULL)
			global.top = new_node;
		new_node->next = *stack;
		if (*stack)
			(*stack)->prev = new_node;
		*stack = new_node;
	}
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
