#include "main.h"

/**
* _puts - prints a string, followed by a new line, to stdout.
* @str: pointer to a character
*
* Return: void
*/
void _puts(char *str)
{
	while (*str)
	{
		_putchar(*str++);
	}
	_putchar('\n');
}
