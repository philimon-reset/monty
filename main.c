#include "monty.h"

/**
 * main - main function
 * @argc: number of arguments
 * @argv: array of pointers
 *
 * Return: 0
 */

int main(int argc, char *argv[]))
{
	int line_n = 1;
	char *line = NULL;
	char *value = NULL, *p, *temp;
	FILE *stream;
	size_t num = 0;
	size_t line_len;

	if (argc != 2)
	{
		fprint(strerr, "USAGE: monty file\n");
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
		if (p = valid(line))
		{
			strcpy(temp, p);
			value = p + strlen(p) - 1;
			if (*value == '\n')
			{
				*value = 0;
			}
			/** value plus other string, check if first character is space and second character is int **/
			if (*temp != ' ')
			{
				;
			}
			temp += strspn(temp, ' ');
		}
		else
		{
			line -= strspn(line, ' ');/** find a way to get the first string of the opcode **/
			fprint(strerr, "L%d: unknown instruction %s\n", line_n, line);
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
char **checker(char *line)
{
	
}
