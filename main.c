/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
  
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
	char *operand = NULL;
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
		if (checker(temp))
		{
		    temp = checker(temp);
			fo = get_op(line);
			value = temp + strlen(temp) - 1;
			if (*value == '\n')
			{
				*value = 0;
			}
			if (*temp != ' ')/** value plus other string, check if first character is a new_line(different error if so) **/
			{
				token = strtok(line, " ");
				fprintf(stderr, "L%d: unknown instruction %s\n", line_n, token);
				free(temp);
				exit(EXIT_FAILURE);
			}
			else
			{
				operand = temp + strspn(temp, " ");
				printf("%s\n", operand);
				fo(&head, line_n);
			}
		}
		else
		{
			token = strtok(line, " ");
			fprintf(stderr, "L%d: unknown instruction %s\n", line_n, token);
			free(temp);
			exit(EXIT_FAILURE);
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
char* checker(char *line)
{
	int i = 0;
	char *av[] = {"push", "pall"};

	line += strspn(line," \t");
	while (av[i] != NULL)
	{
		if (strncmp(line, av[i], strlen(av[i])) == 0)
		{
			line += strlen(av[i]);
			return (line);
		}
		i++;
	}
	return (NULL);
}
