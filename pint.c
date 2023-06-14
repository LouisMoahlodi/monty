#include "monty.h"
/**
 * f_pint - prints the top element of the stack
 * @head: stack head
 * @counter: line number
 * 
 * Return: void
 */
void f_pint(stack_t **head, unsigned int counter)
{
    /* Check if the stack is empty*/
    if (*head == NULL)
    {
        /* Print error message and exit if stack is empty */
        fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    /* Print the value of the top element*/
    printf("%d\n", (*head)->n);
}