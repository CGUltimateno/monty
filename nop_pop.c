#include "monty.h"
/**
 * nop - Removes the top element from the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the current operation
 * Return :Nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
    UNUSED(stack);
    UNUSED(line_number);
}
/**
 * pop - Removes the top value element of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || stack == NULL)
    {
        print_empty_stack_error(line_number);
    }
    else
    {
        delete_top_node(stack);
    }
}
/**
 * print_empty_stack_error - Prints an error
 * message and terminates the program
 * @line_number: Line number of the current operation
 */
void print_empty_stack_error(int line_number)
{
    fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
    free_everything();
    exit(EXIT_FAILURE);
}

