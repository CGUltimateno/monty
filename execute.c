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
    size_t line_length = 0;
    ssize_t read;
    file = fopen(file_name, "r");
    if (file == NULL)
        print_open_file_error(file_name);
    my_data.file = file;

    free_stack(my_data.stack);
    fclose(file);
    free(line);
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