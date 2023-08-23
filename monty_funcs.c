#include "monty.h"

/**
 * push - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void push(stack_t **stack, unsigned int line_number)
{
    int num = 0;

    if (my_data.arg2)
    {
        if (is_num(my_data.arg2))
        {
            num = atoi(my_data.arg2);
            if (my_data.mode == STACK)
                add_dnodeint(stack, num);
            else
                add_stackint_end(stack, num);
        }
        else
            print_push_error(line_number);

    }
    else
        print_push_error(line_number);
}
/**
 * print_push_error - Prints an error message and terminates the program
 * @line_number: Line number of the current operation
 */

void print_push_error( int line_number)
{
    fprintf(stderr, "L%d: usage: push integer\n", line_number);
    free_everything();
    exit(EXIT_FAILURE);
}
/**
 * pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */

void pall(stack_t **stack, unsigned int line_number)
{
    UNUSED(line_number);
    print_stack(*stack);
}
/**
 * free_everything - .
 */

void free_everything(void)
{
    free_stack(my_data.stack);
    free(my_data.file);
    fclose(my_data.line);
}
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