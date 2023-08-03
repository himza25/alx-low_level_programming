#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The bit
 * @index: The index to get the bit at
 *
 * Return: The value of bit at index or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > (sizeof(unsigned long int) * 8))
		return (-1);

	return ((n >> index) & 1);
}
