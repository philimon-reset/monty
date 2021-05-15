#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *line;


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *checker2(char *line);
void argcc(int argc_n);
void checker(char *line);
int token(char *s);
/** helper **/
size_t stack_len(const stack_t *h);
size_t print_stack(const stack_t *h);
size_t stack_len2(const stack_t *h);
int sum_stack(stack_t *head);

/** helper2 **/
void push(stack_t **stack, unsigned int line_number);
void print_stacks(stack_t **stack, unsigned int linen __attribute__((unused)));
int skip_tabs(char *line);
int get_num(char *line, int line_number);
void error_p(char *line, int line_n, stack_t **stack);

/** helper3 **/
void pint(stack_t **stack, unsigned int ln);
void pop(stack_t **stack, unsigned int ln);
void swap(stack_t **stack, unsigned int ln);
void nop(stack_t **stack, unsigned int line_number);

/** utili **/
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_stack(stack_t *head);
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index);
stack_t *get(stack_t *head, unsigned int index);

/** utili2 **/
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n);
stack_t *add(stack_t **head, stack_t *new_node);
stack_t *end(stack_t **head, stack_t *new_node);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
void (*get_op(char *line))(stack_t **stack, unsigned int line_number);

/** utili3 **/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
unsigned min(unsigned int a, unsigned int b);

#endif /*MONTY_H*/
