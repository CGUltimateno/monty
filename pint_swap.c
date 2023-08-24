#include "monty.h"
/**
 * pint - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */

void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || stack == NULL)
    {
        print_pint_error(line_number);
    }
    else
    {
        printf("%d\n", (*stack)->n);
    }
}
/**
 * print_pint_error - Prints an error
 * message and terminates the program
 * @line_number: Line number of the current operation
 */
void print_pint_error(int line_number)
{
    fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
    free_everything();
    exit(EXIT_FAILURE);
}
/**
 * swap - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
    int tmp;
    if (!*stack || !(*stack)->next)
    {
        print_swap_error(line_number);
    }
    if ((*stack)->next)
    {
        tmp = (*stack)->n;
        (*stack)->n = (*stack)->next->n;
        (*stack)->next->n = tmp;
    } else
    {
        print_swap_error(line_number);
    }
}
/**
* print_swap_error - Prints an error
* message and terminates the program
* @line_number: Line number of the current operation
*/

void print_swap_error(int line_number)
{
    fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
    free_everything();
    exit(EXIT_FAILURE);
}