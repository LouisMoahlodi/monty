#include "monty.h"
/**
 * free_stack - Frees a doubly linked list
 * @head: head of the stack
 */
void free_stack(stack_t *head)
{
    stack_t *aux;

    /* Create a auxiliary pointer to keep track of the next node*/
    aux = head;

    /* Traverse the linked list and free each node*/
    while (head)
    {
        /* Update the auxiliary pointer to the next node*/
        aux = head->next;

        /* Free the current node*/
        free(head);

        /* Move the next node*/
        head = aux;
    }
}