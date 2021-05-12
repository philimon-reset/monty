#include "monty.h"

char *operand = NULL;
/**
 * main - main function
 * @argc: number of arguments
 * @argv: array of pointers
 *
 * Return: 0
 */

int main(int argc, char *argv[]))
{
	stack_t *head == NULL;
	int line_n = 1;
	char *av[] = {"push", "pall"};
	char *line = NULL, *value = NULL, *p, *temp, *token;
	FILE *stream;
	size_t num = 0, line_len;

	void (*fo)(stack_t **stack, unsigned int line_number);
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], 'r');
	if (stream == NULL)
	{
		/** Error: Can't open file <file> **/
		exit(EXIT_FAILURE);
	}
	while ((line_len = getline(&line, &num, stream)) != -1)
	{
		if (temp = checker(line))
		{
			fo = get_op(line);
			value = temp + strlen(temp) - 1;
			if (*value == '\n')
			{
				*value = 0;
			}
			if (*temp != '\n')
			{
				fprintf(strerr, "L%d: usage: push integer\n", line_n);
				exit(EXIT_FAILURE);
			}
			if (*temp != ' ')/** value plus other string, check if first character is a new_line(different error if so) **/
			{
				token = strtok(line, ' ');
				fprintf(stderr, "L%d: unknown instruction %s\n", line_n, token);
				exit(EXIT_FAILURE);
			}
			else
			{
				operand = temp + strspn(temp, ' ');
				fo(&head, line_n);
			}
		}
		else
		{
			token = strtok(line, ' ');
			fprintf(stderr, "L%d: unknown instruction %s\n", line_n, token);
			exit(EXIT_FAILURE);
		}
		line_n++;
	}
	return (0);
}

/**
 * checker - checks if value given is valid
 * @line: current line to be checked
 *
 * Return: stack to be added if valid
 */
char *checker(char *line)
{
	char p[100];
	int i = 0;
	char *av[] = {"push", "pall"};

	strcpy(p, line);
	p = skip_tabs(line);
	while (av[i] != NULL)
	{
		if (strncmp(p, av[i], strlen(av[i])) == 0)
			return p + strlen(av[i]);
		i++;
	}
	return NULL;
}
