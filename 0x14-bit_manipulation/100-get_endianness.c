#include "main.h"

/**
 * get_endianness - Checks the system's endianness.
 *
 * Return: 1 if little endian, 0 if big endian.
 */
int get_endianness(void)
{
	unsigned int x = 1;

	return (*(char *)&x == 1 ? 1 : 0);
}
