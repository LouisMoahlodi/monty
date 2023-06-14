#include "monty.h"

/**
 * f_pall - pritns the stack
 * 
 * @head: stack head
 * @counter: no used
 * 
 * Return: void
 */
int free_stack(stack_t *head)
{
    return 0;
}
void f_pall(stack_t **head, unsigned int counter)
{
    stack_t *h;

    /* Suppress unused variable warning*/
    (void)counter;

    /* Assign the stack head to a local variable*/
    h = *head;

    /* If the stack is empty, return early*/
    if (h == NULL)
    return;

        /* Traverse the stack and print each element*/
    while (h)
    {
        printf("%d\n", h->n);
        h = h->next;
    }
}