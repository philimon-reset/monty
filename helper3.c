#include "monty.h"

/**
 * push - add to the begining of the list.
 * @stack: head of list.
 * @line_number: line_number.
 *
 * Return: void function.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	const stack_t *temp = *stack;
	int nodes = 0;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		break;
	}
}
