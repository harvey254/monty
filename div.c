#include "monty.h"
/**
 *div_op -Function to divide the second top element of the stack by the top element
 *@stack:
 *@line_number:
 */
void div_op(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        printf("L%d: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        printf("L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n /= (*stack)->n;
    pop(stack, line_number);
}

