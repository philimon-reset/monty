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
 * Return: void function
 */
void pop(stack_t **stack, unsigned int ln)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * swap - swaps the top two elements of the stack.
 * @stack: head of list.
 * @ln: index to delete.
 *
 * Return: void function
 */
void swap(stack_t **stack, unsigned int ln)
{
	stack_t *temp = *stack;
	int i = 0;

	if (stack_len(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
		stack = stack->next;
	}
	((*stack)->prev)->n = temp->n;
	(*stack)->n = (temp->prev)->n;
	free(temp);
}
