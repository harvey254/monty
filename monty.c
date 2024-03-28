#include "monty.h"
#include <stdio.h>
/**
 * main - monty program
 *
 * Return: 0 Success, -1 otherwise
 */

stack_t *stack = NULL;

int main(void)
{
    char *line = NULL;
    char *read;
    unsigned int line_number = 0;
    char *opcode = strtok(line, " \n");
    int found = 0;
    int i;

    instruction_t instructions[] = {
        {"push", _push},
        {"pall", _pall},
        {"pint", _pint},
        {"pop", _pop},
        {"swap", _swap},
        {"add", _add},
        {"sub", _sub},
        {"div", div_op},
        {"mul", _mul}, 
        {"nop", _nop},
        {NULL, NULL}
    };
    read = fgets(line, sizeof(line), stdin);

    while (read != NULL)
    {
        line_number++;
        if (opcode == NULL || strlen(opcode) == 0 || opcode[0] == '#')
            continue;
        for (i = 0; instructions[i].opcode != NULL; i++)
        {
            if (strcmp(opcode, instructions[i].opcode) == 0)
            {
                instructions[i].f(&stack, line_number);
                found = 1;
                break;
            }
        }
        if (!found)
            printf("L%d: unknown instruction %s\n", line_number, opcode);
    }

    free(line);
    free(stack);
    return 0;
}
