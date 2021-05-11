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
	int line_n = 0;
	char *line = NULL;
	FILE *stream;
	size_t num = 0;

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
	if (getline(&line, &num, stream) != -1)
	{
		;
	}
	return (0);
}
