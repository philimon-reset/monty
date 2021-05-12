#include "monty.h"


/**
 * push - add to the begining of the list.
 * @stack: head of list.
 * @nline_number: line_number
 *
 * Return: void function
 */

void *push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		return (NULL);
	new_node->n = get_num(line_number);/** make the funtion **/
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
}

/**
 * print_stacks - print all the elements in the list.
 * @h: head of the list.
 *
 * Return: returns the number of nodes.
 */

void print_stacks(stack_t **stack, unsigned int line_number)
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
 * skip_tabs - skips the tabs to the first character
 * @line: line to be checked
 *
 * Returns: line begining with the first character.
 */
char *skip_tabs(char *line)
{
	return line + strspn(line," \t");
}

/**
 * valid - checkes if given value is in line
 * @line: line to be checked
 *
 * Returns: address of line after given value or NULL
 */
char *valid(char *line)
{
	char *p;
	int i = 0;
	char *av[] = {"push", "pall"};

	p = skip_tabs(line);
	while (av[i] != NULL)
	{
		if (strncmp(p, av[i], strlen(av[i])) == 0)
			return p + strlen(av[i]);
	}
	return NULL;
}

