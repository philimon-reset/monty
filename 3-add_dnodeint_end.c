#include "monty.h"

/**
 * add_dnodeint_end - add new node at the end of the list.
 * @head: head of list.
 * @n: value of the node.
 *
 * Return: address of new node.
 */

dlistint_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *temp = *head;

	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*head == NULL)
	{
		(*head) = new_node;
		return (new_node);
	}
	while (temp != NULL && temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new_node;
	new_node->prev = temp;
	return (new_node);
}
