#include "monty.h"
/**
 * pop- Function to remove the top element of the stack
 * @stack:
 * @line_number:
 *
 * Return: no value
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = top->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(top);
}
