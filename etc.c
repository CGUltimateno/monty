#include "monty.h"

/**
 * is_num - Checks if a string represents a valid integer
 * @num: The string to check
 *
 * Return: 1 if the string is a valid integer, 0 otherwise
 */

int is_num(char *num)
{
    int i = 0;

    if (num[i] == '-')
        i++;

    for (; num[i]; i++)
    {
        if (!(num[i] >= '0' && num[i] <= '9'))
            return (0);
        i++;
    }

    return (1);
}