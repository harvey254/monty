#include "monty.h" 
/**
  * swap- function to swap the top two elements of the stack 
  * @stack:
  * @line_number:
  * Return: no value
  */
void swap(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        printf("L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *top1 = *stack;
    stack_t *top2 = (*stack)->next;

    top1->prev = top2;
    top1->next = top2->next;
    if (top2->next != NULL)
        top2->next->prev = top1;
    top2->prev = NULL;
    top2->next = top1;

    *stack = top2;
}
