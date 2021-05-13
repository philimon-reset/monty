#include "monty.h"

/**
 * push - add to the begining of the list.
 * @stack: head of list.
 * @ln: line_number.
 *
 * Return: void function.
 */

void pint(stack_t **stack, unsigned int ln __attribute__ ((unused)))
{
	const stack_t *temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		break;
	}
}