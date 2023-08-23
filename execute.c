#include "monty.h"
/**
 * execute_file - Executes the operations in a file
 * @file_name: Name of the file containing the operations
 *
 * Return: 0 on success, -1 on failure
 */
int execute_file(char *file_name)
{
    FILE *file = NULL;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    char *opcode_instruction = NULL;
    void (*op_func)(stack_t **, unsigned int);
    stack_t *stack = NULL;
    my_data.file_name = file_name;
    file = fopen(file_name, "r");
    if (!file)
        print_open_file_error(file_name);
    while (getline(&line, &len, file) != -1)
    {
        line_number++;
        opcode_instruction = strtok(line, "\n\t\r ");
        if (!opcode_instruction || opcode_instruction[0] == '#')
            continue;
        if (strcmp(opcode_instruction, "push") == 0)
        {
            my_data.arg2 = strtok(NULL, "\n\t\r ");
            push(&stack, line_number);
        }
        else
        {
            op_func = get_op_func(opcode_instruction);
            if (!op_func)
                print_invalid_instruction_error(line_number, opcode_instruction);
            op_func(&stack, line_number);
        }
    }
    free(line);
    fclose(file);
    free_stack(stack);
    return (0);
}
/**
 * execute_line - Executes a single line of operation
 * @line: Line of operation
 * @line_number: Line number of the current operation
 */
 void execute_line(char *line,  int line_number)
{
     int i;
     int is_instruction  = 0;
    instruction_t  instructions[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
    };
    my_data.arg1 = strtok(line, " \n");
    my_data.arg2 = strtok(NULL, " \n");
    if (my_data.arg1[0] == '#')
    {
        nop(&my_data.stack, line_number);
        return;
    }
    for (i = 0; i < INSTRUCTIONS_COUNT; i++)
        if (strcmp(my_data.arg1, instructions[i].opcode) == 0)
        {

            is_instruction = i;
            break;
        }
    if (is_instruction != -1)
        instructions[i].f(&my_data.stack, line_number);
    else
        print_invalid_instruction_error(line_number, my_data.arg1);
}

/**
 * is_empty_line - .
 * @line: Line to check
 *
 * Return: 1 if the line is empty, 0 otherwise
 */
 int is_empty_line(char *line)
{
     int i;
     int len = strlen(line);
    if (len > 0)
    {
        if (line[len - 1] == '\n')
        {
            for (i = 0; i < len - 1; i++)
            {
                if (line[i] != ' ')
                    return (1);
            }
            return (0);
        }
    }

    return (0);
}