#include "lists.h"

/**
 * print_address - Prints an unsigned long int.
 * @address: The address to be printed.
 *
 * Return: void.
 */
void print_address(unsigned long int address)
{
	if ((address / 16) > 0)
		print_address(address / 16);
	_putchar("0123456789abcdef"[address % 16]);
}

/**
 * print_int - Prints an integer.
 * @n: The integer to be printed.
 *
 * Return: void.
 */
void print_int(int n)
{
	if ((n / 10) > 0)
		print_int(n / 10);
	_putchar('0' + n % 10);
}
