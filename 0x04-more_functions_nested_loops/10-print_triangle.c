#include "main.h"

/**
 * print_triangle - prints a triangle.
 * @size: the size of the triangle.
 * Return: Nothing.
 */
void print_triangle(int size)
{
    int i, j, space;

    if (size > 0)
    {
        for (i = 0; i < size; i++)
        {
            for (space = size - i; space > 1; space--)
            {
                _putchar(' ');
            }
            for (j = 0; j <= i; j++)
            {
                _putchar('#');
            }
            _putchar('\n');
        }
    }
    else
    {
        _putchar('\n');
    }
}
