#include "monty.h"

/**
 * print_stack - print all the elements in the list.
 * @h: head of the list.
 *
 * Return: returns the number of nodes.
 */

void print_stack(stack_t **stack, unsigned int line_number)
{
	const stack_t *temp = *stack;
	int nodes = 0;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		nodes++;
		temp = temp->next;
	}
}


/**
 * stack_len - counts the elements in the list.
 * @h: head of the list.
 *
 * Return: returns the number of nodes.
 */

size_t stack_len(const stack_t *h)
{
	const stack_t *temp = h;
	int nodes = 0;

	while (temp != NULL)
	{
		nodes++;
		temp = temp->next;
	}
	return (nodes);
}

/**
 * stack_len2 - counts the elements in the list.
 * @h: head of the list.
 *
 * Return: returns the number of nodes.
 */

size_t stack_len2(const stack_t *h)
{
	const stack_t *temp = h;
	int nodes = 0;

	while (temp != NULL)
	{
		nodes++;
		temp = temp->next;
	}
	return (nodes);
}

/**
 * sum_stack - sum of data in list.
 * @head: head of list.
 *
 * Return: total data.
 */

int sum_stack(stack_t *head)
{
	stack_t *temp = head;
	int total = 0;

	while (temp != NULL)
	{
		total += temp->n;
		temp = temp->next;
	}
	return (total);
}
