#include "monty.h"

/**
 * add_dnodeint - add to the begining of the list.
 * @head: head of list.
 * @n: value of new list
 *
 * Return: returns the address of the new element.
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	else
	{
		new_node->next = (*head);
		(*head)->prev = new_node;
		*head = new_node;
	}
	return (new_node);
}


/**
 * add_dnodeint_end - add new node at the end of the list.
 * @head: head of list.
 * @n: value of the node.
 *
 * Return: address of new node.
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
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

/**
 * get_dnodeint_at_index - get the addressof node at given index.
 * @head: head of list.
 * @index: index of needed node.
 *
 * Return: address of indexed node.
 */

stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
{
	stack_t *temp = head;
	unsigned int size = 0, node = 0;

	size = stack_len2(head);
	if (index >= size)
		return (NULL);
	while (temp != NULL)
	{
		if (index == node)
			return (temp);
		node++;
		temp = temp->next;
	}
	return (NULL);
}

/**
 * get - get the address of node at given index.
 * @head: head of list.
 * @index: index of needed node.
 *
 * Return: address of indexed node.
 */

stack_t *get(stack_t *head, unsigned int index)
{
	stack_t *temp = head;
	stack_t *temp2 = head;
	unsigned int node = 0, size = 0;

	while (temp2 != NULL)
	{
		size++;
		temp2 = temp2->next;
	}
	if (index > size)
		return (NULL);
	while (temp != NULL)
	{
		if (index == node)
			break;
		node++;
		temp = temp->next;
	}
	if (node != index)
		return (NULL);
	return (temp);
}
