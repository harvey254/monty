#include "monty.h"
/**
 * pop- Function to remove the top element of the stack
 * @stack:
 * @line_number:
 *
 * Return: no value
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *top = *stack;
	*stack = top->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(top);
}
