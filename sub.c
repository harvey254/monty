#include "monty.h"
/**
 * _sub - Function to subtract the top element of the stack from the second top element 
 * @stack:
 * @line_number
 *
 * Return:no value
 */
void _sub(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        printf("L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n -= (*stack)->n;
    _pop(stack, line_number);
}
