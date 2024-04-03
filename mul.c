#include "monty.h"
/**
 * _mul -
 * @stack:
 * @line_number
 *
 * Return: no value
 */
void _mul(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        printf("L%d: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n *= (*stack)->n;
    _pop(stack, line_number);
}
