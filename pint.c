#include "monty.h"
/**
 * pint - Function to print the value at the top of the stack 
 * @stack:
 * @line_number:
 *
 * Return: no value
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
