#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points the next element of the stack (or queue)
 * 
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;
/**
 * struct instructions_s - opcode and its functions
 * @opcode: the opcode
 * @f: function thto handle the opcode
 * 
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t *stack, unsigned int line_number);
} instruction_t;
/**
 * struct bus_s - variable -args, file, line content
 * @args: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag chane stack <-> queue
 * 
 * Description: carries values through the program
 */
typedef struct bus_s
{
    char *args;
    FILE *file;
    char *content;
    int lifi;
} bus_t;
extern bus_t bus;

int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
free_stack(stack_t *head);
void f_push(stack_t *head, unsigned int counter);
void f_pall(stack_t **head, unsigned int counter)







#endif