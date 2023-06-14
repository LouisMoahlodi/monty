#include "monty.h"
/* execute - executes the opcode
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: pointer to monty file
 * @content: line content
 * Return: no return
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
		{"pop", f_pop},
		/*{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{"sub", f_sub},
		{"div", f_div},
		{"mul", f_mul},
		{"mod", f_mod},
		{"pchar", f_pchar},
		{"pstr", f_pstr},
		{"rotl", f_rotl},
		{"rotr", f_rotr},*/
		{"queue", f_queue},
		/*{"stack", f_stack},*/
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");  /* Extract the opcode from the line content */
	if (op && op[0] == '#')
		return (0);  /* Ignore comment lines by checking if the opcode starts with '#' */

	bus.arg = strtok(NULL, " \n\t");  /* Extract the argument for the opcode (if any) */

	/* Iterate through the instruction array to find a matching opcode */
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);  /* Execute the corresponding function for the opcode */
			return (0);
		}
		i++;
	}

	/* If the opcode is not found in the instruction array */
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
