#include "monty.h"
/**
 * f_pop - Removes the top element from the stack
 * @head: stack head
 * @counter: line number
 * 
 * Return: void
 */
int free_stack(stack_t *head)
{
    return 0;
}
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	/* Check if the stack is empty*/
	if (*head == NULL)
	{
		/* Print error message and exit if the stack is empty*/
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/* Store the current top element in temporary variable */
	h = *head;

	/* Update the head to point to the next element*/
	*head = h->next;

	/* Free the memory occupied by the previous top element*/
	free(h);
}