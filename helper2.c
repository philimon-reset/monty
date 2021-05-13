#include "monty.h"

/**
 * push - add to the begining of the list.
 * @stack: head of list.
 * @nline_number: line_number
 *
 * Return: void function
 */

void push(stack_t **stack, unsigned int line_number)
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
	}
	else
	{
		new_node->next = (*stack);
		(*stack)->prev = new_node;
		*stack = new_node;
	}
	free(new_node);
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
 * skip_tabs - skips the unprintable characters
 * @line: line to be checked
 *
 * Returns: void function
 */
int skip_tabs(char *line)
{
	int i = 0, a = 0;
	char *av[] = {"push", "pall"};

	while (i < 2)
	{
		if (strncmp(line, av[i], strlen(av[i])) == 0)
		{
			a = strlen(av[i]);
			break;
		}
		i++;
	}
	return (a);
}

/**
 * get_num - get the int needed or exit if not applicable.
 * @operand: value to be converted
 *
 * Returns: correct value if valid or exit if not
 */
int get_num(char *operand, int line_number)
{
	if (*operand == '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (*operand < 48 || *operand > 57)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	return (atoi(operand));
}

/**
 * error_p - check if error is present.
 * @line: line to be checked for token
 * @line_n: line number
 *
 * Return: void function
 */
void error_p(char *line, int line_n)
{
	char *token;
	char *val;

	val = strdup(line);
	token = strtok(val, " ");
	if (strncmp(token, "pall", 4) == 0)
	{
		free(val);
		return;
	}
	else if (*line != ' ')
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_n, token);
		free(val);
		exit(EXIT_FAILURE);
	}
	free(val);
}
