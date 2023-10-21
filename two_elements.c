#include "monty.h"

/**
 * two_elements_check - Checks if minimum two elements in stack
 * @err: What function did the error occur in
 * @line_number: Line number
 */
void two_elements_check(char *err, unsigned int line_number)
{
	if (!(global.top) || !((global.top)->prev))
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, err);
		free_stack();
		exit(EXIT_FAILURE);
	}
}
