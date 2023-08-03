#include "main.h"

/**
 * flip_bits - Counts the number of bits needed.
 * @n: The first number
 * @m: The second number
 *
 * Return: The number of bits you would need to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor = n ^ m;
	unsigned int bit_count = 0;

	while (xor > 0)
	{
		bit_count += (xor & 1);
		xor >>= 1;
	}

	return (bit_count);
}
