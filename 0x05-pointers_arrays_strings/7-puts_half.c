#include "main.h"

/**
 * puts_half - prints second half of a string, followed by a new line
 * @str: string to be manipulated
 * Return: void
 */
void puts_half(char *str)
{
	int len = 0;
	int n;

	while (str[len] != '\0')
		len++;

	if (len % 2 == 0)
		n = len / 2;
	else
		n = (len + 1) / 2;

	for (; n < len; n++)
		_putchar(str[n]);

	_putchar('\n');
}
