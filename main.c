#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
 * main - monty code interpreter
 * 
 * @argc: number of arguments 
 * @argv: monty file location 
 * 
 * Return: 0 on success 
 */
int free_stack(stack_t *head)
{
    return 0;
}
int main(int argc, char *argv[])
{
    char *content;
    FILE *file;
    size_t size = 0;
    ssize_t read_line = 1;
    stack_t *stack = NULL;
    unsigned int counter = 0;

    /* Check if the number of arguments is correct*/
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* Open the file */
    file = fopen(argv[1], "r");
    bus.file = file;
    /* Check if the opening was successful*/
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (read_line > 0)
    {
        content = NULL;
        /* Read each line from the file */
        read_line = getline(&content, &size, file);
        bus.content = content;
        counter++;
        if (read_line > 0)
        {
            /*Execute the instruction and check for errors*/
            if (execute(content, &stack, counter, file) == EXIT_FAILURE)
            {
                free(content);
                free_stack(stack);
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
        /* Free the memory alloacted for the line content*/
        free(content);
    }

    /* Free the memory allocated for the stack */
    free_stack(stack);
    /* Close the file*/
    fclose(file);

    return (0);
}