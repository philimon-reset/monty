#include "monty.h"

/**
 * push - add to the begining of the list.
 * @stack: head of list.
 * @line_number: line_number.
 *
 * Return: void function.
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	int value = get_num(line, line_number);

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_node);
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
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
}

/**
 * print_stacks - print all the elements in the list.
 * @stack: head of the list.
 * @linen: line number.
 *
 * Return: returns the number of nodes.
 */

void print_stacks(stack_t **stack, unsigned int linen __attribute__((unused)))
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
 * skip_tabs - skips the unprintable characters.
 * @line: line to be checked.
 *
 * Return: int line.
 */
int skip_tabs(char *line)
{
	int i = 0, a = 0;
	char *av[] = {"push", "pall", "pint"};

	while (i < 3)
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
 * @line: value to be converted.
 * @line_number: line number.
 *
 * Return: correct value if valid or exit if not.
 */
int get_num(char *line, int line_number)
{
	if (*line == '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (*line < 48 || *line > 57)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	return (atoi(line));
}

/**
 * error_p - check if error is present.
 * @line: line to be checked for token.
 * @line_n: line number.
 * @stack: stack head.
 *
 * Return: void function.
 */
void error_p(char *line, int line_n, stack_t **stack)
{
	char *token, *av[] = {"pall", "pint", "pop", "swap"};
	int a = 0;
	char *val;
	char str[] = {"push"};

	val = strdup(line);
	token = strtok(val, " ");
	if (token == NULL)
	{
		free(val);
		free(line);
		free_stack(*stack);
		fprintf(stderr, "L%d: usage: push integer\n", line_n);
		exit(EXIT_FAILURE);
	}
	while (a < 4)
	{
		if (strncmp(line, av[a], 4) == 0)
		{
			free(val);
			return;
		}
		a++;
	}
	if (*line != ' ')
	{
		strcat(str, token);
		fprintf(stderr, "L%d: unknown instruction %s\n", line_n, str);
		free_stack(*stack);
		free(val);
		exit(EXIT_FAILURE);
	}
	free(val);
}
