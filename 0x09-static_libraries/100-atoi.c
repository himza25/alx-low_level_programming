#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the integer value of the converted string
 */
int _atoi(char *s)
{
	int res = 0;
	int sign = 1;
	int flag = 0;

	for (; *s != '\0'; ++s)
	{
		if (*s == '-')
			sign *= -1;

		if (*s >= '0' && *s <= '9')
		{
			res *= 10;
			res -= (*s - '0');
			flag = 1;
		}

		else if (flag)
			break;
	}

	return (res * -sign);
}
