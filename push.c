#include "monty.h"

/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line number
 * 
 * Return: Void
 */
void f_push(stack_t **head, unsigned int counter)
{
    int n, j = 0, flag = 0;

    /* Check if the argument (bus.arg) i not NULL or empty*/
    if (bus.arg)
    {
        /* Check if the argument starts with a '-' character*/
        if (bus.arg[0] == '-')
        j++;

        /* Iterate over each character of the argument*/
        for (; bus.arg[j] != '\0'; j++)
        {
            /* Check if the character is not a digit*/
            if (bus.arg[j] > 57 || bus.arg[j] < 48)
            flag = 1;
        }

        /* If the flag is set to 1, it means the argument is not a valid integer*/
        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(bus.file);
            free(bus.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* If the argument is NULL or empty, it's an error*/
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    /* Convert the argument (bus.arg) to an integer*/
    n = atoi(bus.arg);

    /* Determine whether to add the node to the stack or queue based on bus.lifi value*/
    if (bus.lifi == 0)
        addnode(head, n);
    else
        addqueue(head, n);
}