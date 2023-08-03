#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int
 * @b: The binary number
 *
 * Return: The unsigned int
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int res = 0;
	int base = 1;
	int len = 0;

	if (b == NULL)
		return (0);

	while (b[len])
		len++;

	for (len -= 1; len >= 0; len--)
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);

		res += (b[len] - '0') * base;
		base *= 2;
	}

	return (res);
}
