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
	int line_n = 1;
	char *line = NULL;
	char *value = NULL;
	char *temp = NULL;
	char *token;
	FILE *stream;
	size_t num = 0;

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
	while (getline(&line, &num, stream) != -1)
	{
		temp = strdup(line);
		checker(temp);
		fo = get_op(temp);
		if (fo)
		{
			skip_tabs(temp);
			error_p(line, temp, line_n);
			operand = temp + strspn(temp, " ");
			printf("%s\n", operand);
			fo(&head, line_n);
		}
		else
		{
			error_p(line, temp, line_n);
		}
		line_n++;
	}
	fclose(stream);
	return (0);
}

/**
 * checker - checks if value given is valid
 * @line: current line to be checked
 *
 * Return: stack to be added if valid
 */
void* checker(char *line)
{
	int i = 0;

	line += strspn(line, " ");
	while (line[i] != '\0')
	{
		if (line[i] < ' ' || line[i] > 126)
			break;
		i++;
	}
	line[i] = '\0';
}
