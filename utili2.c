#include "monty.h"

/**
 * insert_dnodeint_at_index - insert new node at given index.
 * @h: head of list.
 * @idx: index to add in.
 * @n: value to add.
 *
 * Return: address of new node.
 */
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n)
{
	stack_t *new_mode;
	unsigned int size = 0;
	stack_t *temp = NULL, *op = NULL;

	if (h == NULL)
		return (NULL);
	op = *h;
	while (op != NULL)
	{
		size += 1;
		op = op->next;
	}
	if (idx > size)
		return (NULL);
	temp = get(*h, idx);
	new_mode = malloc(sizeof(stack_t));
	if (new_mode == NULL)
		return (NULL);
	new_mode->n = n;
	new_mode->next = NULL;
	new_mode->prev = NULL;
	if (idx == 0 || size == 0)
	{
		new_mode = add(h, new_mode);
		return (new_mode);
	}
	if (idx == size)
	{
		new_mode = end(h, new_mode);
		return (new_mode);
	}
	if (temp->prev != NULL)
	{
		new_mode->prev = temp->prev;
		(temp->prev)->next = new_mode;
	}
	new_mode->next = temp;
	temp->prev = new_mode;
	return (new_mode);
}

/**
 * delete_dnodeint_at_index - delete node at given index.
 * @head: head of list.
 * @index: index to delete.
 *
 * Return: 1 if successs -1 if not
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *temp = *head;
	unsigned int size = 0, node = 0;

	if (head == NULL)
		return (-1);
	for (size = 0; temp != NULL; size++)
		temp = temp->next;
	if (index >= size || size == 0)
		return (-1);
	temp = *head;
	for (; node != index; node++, temp = temp->next)
	{
		;
	}
	if (*head == temp)
	{
		*head = temp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}
	(temp->prev)->next = temp->next;
	if (temp->next != NULL)
		(temp->next)->prev = temp->prev;
	free(temp);
	return (1);
}

/**
 * add - add to the begining of the list.
 * @head: head of list.
 * @new_node: value of new list
 *
 * Return: returns the address of the new element.
 */
stack_t *add(stack_t **head, stack_t *new_node)
{
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
 * end - add new node at the end of the list.
 * @head: head of list.
 * @new_node: value of the node.
 *
 * Return: address of new node.
 */

stack_t *end(stack_t **head, stack_t *new_node)
{
	stack_t *temp = *head;

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
 * get_op - get the proper opcode.
 * @line: string to be checked
 *
 * Return: function needed or else NULL
 */
void (*get_op(char *line))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	void (*fo)(stack_t **stack, unsigned int line_number);
	instruction_t func[] = {
		{"push", push},
		{"pall", print_stacks},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};

	line += strspn(line, " ");
	if (strlen(line) < 4)
		return (NULL);
	while (i < 5)
	{
		if (strncmp(line, func[i].opcode, strlen(func[i].opcode)) == 0)
		{
			fo = func[i].f;
			return (fo);
		}
		i++;
	}
	return (NULL);
}
