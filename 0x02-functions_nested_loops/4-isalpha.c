#include "main.h"

/**
 * Function to check for alphabetic character
 *
 * Check if character is an alphabet
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
i}
