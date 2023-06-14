#include "monty.h"
/**
 * f_queue - Chnages stack behaviour to queue
 * 
 * @head: stack head
 * @counter: line_number
 * 
 * Return: void
 */
void f_queue(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;
    bus.lifi = 1;
}
/**
 * addqueue - add node to the tail of the stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void addqueue(stack_t **head, int n)
{
    stack_t *new_node, *aux;

    aux = *head;  /*Store the current head of the stack in auxiliary variable*/

    /*Allocate memory for the new node*/
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("Error\n");
        /*Handle error condition (unable to allocate memory)
        You can modify this part based on your error handling requirements*/
    }

    new_node->n = n;  /*Set the value of the new node*/
    new_node->next = NULL;  /*The next pointer of the new node is set to NULL*/

    if (aux)
    {
        /* Traverse to the last node of the stack*/
        while (aux->next)
            aux = aux->next;
    }

    if (!aux)
    {
        /*If the stack is empty (head is NULL), make the new node as the head*/
        *head = new_node;
        /* The previous pointer of the new node is set to NULL*/
        new_node->prev = NULL;  
    }
    else
    {
        /* Append the new node to the end of the stack */
        aux->next = new_node;
        /* Set the previous pointer of the new node to the last node*/
        new_node->prev = aux;  
    }
}