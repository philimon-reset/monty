#include "monty.h"

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
