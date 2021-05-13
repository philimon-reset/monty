#include "monty.h"

char *operand = NULL;
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
	int line_n = 1, a = 0, space = 0, pa;
	char *line = NULL;
	char *av[] = {"push"};
	char *temp = NULL;
	FILE *stream;
	size_t num = 0;
	unsigned get_;
	void (*fo)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	get_ = getline(&line, &num, stream);
	while (get_ > 0)
	{
		temp = strdup(line);
		space = token(temp);
		if (space == 0)
		{
			free(temp);
			continue;
		}
		fo = get_op(temp);
		free(temp);
		if (fo)
		{
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
			error_p(line, line_n, &head);
			operand = line + strspn(line, " ");
			operand += strspn(operand, " ");
			fo(&head, line_n);
		}
		else
		{
			error_p(line, line_n, &head);
		}
		line_n++;
	}
	free_stack(head);
	fclose(stream);
	return (0);
}

/**
 * checker - checks if value given is valid
 * @line: current line to be checked
 *
 * Return: stack to be added if valid
 */
void checker(char *line)
{
	int i = 0;

	while (line[i] != '\0')
	{
		if (line[i] < ' ' || line[i] > 126)
			break;
		i++;
	}
	line[i] = '\0';	
}

int token(const char *s)
{
	char* temp;
	char* token;

	temp = strdup(s);
	token = strtok(temp, " ");
	if (token == NULL)
	{
		free(temp);
		return (0);
	}
	free(temp);
	return (1);
}
