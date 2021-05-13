#include "monty.h"

/**
 * pint - print begining of stack
 * @stack: head of list.
 * @ln: line_number.
 *
 * Return: void function.
 */

void pint(stack_t **stack, unsigned int ln)
{
	stack_t *temp = *stack;

	if (stack_len(*stack) == 0)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		break;
	}
}

/**
 * pop - delete node at given index.
 * @stack: head of list.
 * @ln: index to delete.
 *
 * Return: 1 if successs -1 if not
 */
void pop(stack_t **stack, unsigned int ln)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = temp->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(temp);
}
