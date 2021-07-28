#include "monty.h"

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size of ptr
 * @new_size: size of the new memory to be allocated
 *
 * Return: pointer to the address of the new memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *temp_block;
	unsigned int i;

	if (ptr == NULL)
	{
		temp_block = malloc(new_size);
		return (temp_block);
	}
	else if (new_size == old_size)
		return (ptr);
	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		temp_block = malloc(new_size);
		if (temp_block != NULL)
		{
			for (i = 0; i < min(old_size, new_size); i++)
				*((char *)temp_block + i) = *((char *)ptr + i);
			return (temp_block);
		}
		else
			return (NULL);
	}
}

/**
 * min - minumum of a and b
 * @a: first integer
 * @b: second integer
 *
 * Return: return the minimum
 */
unsigned int min(unsigned int a, unsigned int b)
{
	if (a < b)
		return (a);
	return (b);
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
/**
 * token - checks if value given is valid
 * @s: current line to be checked
 *
 * Return: 1 or 0
 */

int token(char *s)
{
	char *temp;
	char *token;

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
