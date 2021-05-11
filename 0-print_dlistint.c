#include "monty.h"

/**
 * print_dlistint - print all the elements in the list.
 * @h: head of the list.
 *
 * Return: returns the number of nodes.
 */

size_t print_dlistint(const stack_t *h)
{
	const stack_t *temp = h;
	int nodes = 0;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		nodes++;
		temp = temp->next;
	}
	return (nodes);
}
