#include "monty.h"

char *line = NULL;
/**
 * main - main function
 * @argc: number of arguments
 * @argv: array of pointers
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	stack_t *head = NULL;
	int line_n = 1, space = 0;
	char *temp;
	FILE *stream;
	size_t num = 0;
	void (*fo)(stack_t **stack, unsigned int line_number);
	argcc(argc);
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	file_into_list(stream, head);
	free_stack(head);
	return (0);
}

/**
 * file_into_list - copies the contents of a file into a linked list
 * @stream: file stream
 * @head: head of stack
 *
 * Return: void
 */
void file_into_list(FILE *stream, stack_t *head)
{
	char *temp = NULL;
	size_t num = 0;
	int line_n = 1, space = 0;
	void (*fo)(stack_t **stack, unsigned int line_number);

	while (getline(&line, &num, stream) != -1)
	{
		temp = strdup(line);
		space = token(temp);
		if (space == 0 || strlen(line) < 3)
		{
			free(temp);
			free(line);
			line_n++;
			continue;
		}
		fo = get_op(temp);
		free(temp);
		if (fo)
		{
			line = checker2(line);
			error_p(line, line_n, &head);
			line += strspn(line, " ");
			fo(&head, line_n);
		}
		else
		{
			error_p(line, line_n, &head);
		}
		line_n++;
	}
	fclose(stream);
}

/**
 * argcc - check if argc if valid.
 * @argc_n: argc value.
 *
 * Return: void function.
 */
void argcc(int argc_n)
{
	if (argc_n != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * checker2 - check if argc if valid.
 * @line: string to be checked
 *
 * Return: character pointer
 */
char *checker2(char *line)
{
	int pa, a = 0;
	char *av[] = {"push"};

	checker(line);
	line += strspn(line, " ");
	a = skip_tabs(line);
	pa = 0;
	while (pa < 1)
	{
		if (strncmp(line, av[pa], strlen(av[pa])) == 0)
			line += a;
		pa++;
	}
	return (line);
}
