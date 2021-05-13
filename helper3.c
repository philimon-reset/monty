#include "monty.h"

/**
 * pint - print begining of stack
 * @stack: head of list.
 * @ln: line_number.
 *
 * Return: void function.
 */

void pint(stack_t **stack, unsigned int ln __attribute__ ((unused)))
{
	stack_t *temp = *stack;

	if (stack_len(*stack) == 0)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_n);
		exit(EXIT_FAILURE);
	}
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		break;
	}
}
