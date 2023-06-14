#include "monty.h"
/**
 * addnode - Add node to the head stack
 * 
 * @head: head of the stack
 * n: new_value
 * 
 * Return: void
 */
void addnode(stack_t **head, int n)
{
    stack_t *new_node, *aux;

    /* Create a new node*/
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("Error\n");
        exit(0);
    }

    /* Get the current head of the stack */
    aux = *head;

    /* Update the previous pointer of the current head if it exists*/
    if (aux)
	 	aux->prev = new_node;

	/* Set the value of the new node*/
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
}