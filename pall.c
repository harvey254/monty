#include "monty.h"
/**
 * pall - displays content of the stack
 * @stack:
 * @line_number:
 *
 * Return: no value
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;
	while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
