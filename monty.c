#include "monty.h"
#include <stdio.h>
/**
 * main - monty program
 *
 * Return: 0 Success, -1 otherwise
 */

stack_t *stack = NULL;

int main(int argc, char *argv[])
{
	char *line = NULL;
	char *read;
	unsigned int line_number = 0;
	int found;
	int i;
	char *opcode = strtok(line, " \n");
	FILE *file = fopen(argv[1], "r");
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


    if (argc != 2)
    {
        fprintf(stderr, "USAGE: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while ((read = fgets(line, sizeof(line), file)) != NULL)
    {
        line_number++;
	if (opcode == NULL || strlen(opcode) == 0 || opcode[0] == '#')
            continue; 

        found = 0;
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
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    free(line);
    fclose(file);
    return (0);
}
