#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "monty.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    stack_t *head;

    head = NULL;
    add_dnodeint_end(&head, 0);
    print_stack(head);
    printf("-----------------\n");
    insert_dnodeint_at_index(&head, 5, 4096);
    print_stack(head);
    free_stack(head);
    head = NULL;
    return (EXIT_SUCCESS);
}
