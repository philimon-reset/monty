#include "monty.h"

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
