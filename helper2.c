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
	int value = get_num(operand, line_number);

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_node);
		exit(EXIT_FAILURE);
	}
	new_node->n = value;/** make the funtion **/
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		return (new_node);
	}
	else
	{
		new_node->next = (*stack);
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}

/**
 * print_stacks - print all the elements in the list.
 * @h: head of the list.
 *
 * Return: returns the number of nodes.
 */

void print_stacks(stack_t **stack, unsigned int line_number __attribute__((unused)))
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
 * get_num - get the int needed or exit if not applicable.
 * @operand: value to be converted
 *
 * Returns: correct value if valid or exit if not
 */
int get_num(char *operand, int line_number)
{
	char *val = strdup(operand);

	if (*val == '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(val);
		exit(EXIT_FAILURE);
	}
	while (*val != '\0')
	{
		if (*val < 48 || *val > 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(val);
			exit(EXIT_FAILURE);
		}
	}
	free(val);
	return (atoi(operand));
}
