#include "monty.h"
/**
 * add -Function to add the top two elements of the stack 
 * @stack:
 * @line_number:
 * Return: no value
 */
void _add(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        printf("L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    _pop(stack, line_number);
}
