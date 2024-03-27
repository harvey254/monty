#include "monty.h"
/**
 * push - pushes elements to the stack
 * @stack:
 * @line_number:
 *
 * Return: no value
 */
void push(stack_t **stack, unsigned int line_number)
{
	int num;
	int i;
	char *arg = strtok(NULL, " \n");
	stack_t *new_node = malloc(sizeof(stack_t));
    if (arg == NULL || strlen(arg) == 0)
    {
        printf("L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    num = 0;
    for (i = 0; arg[i] != '\0'; i++)
    {
        if (!isdigit(arg[i]) && !(i == 0 && arg[i] == '-'))
        {
            printf("L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
    }

    num = atoi(arg);
    if (new_node == NULL)
    {
        printf("Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = num;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

