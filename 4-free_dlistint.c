#include "monty.h"

/**
 * free_stack - free all allocated memory.
 * @head: head of linked list.
 *
 * Return: void function.
 */

void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
