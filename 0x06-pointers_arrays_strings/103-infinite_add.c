#include "main.h"

/**
 * infinite_add - Adds two numbers
 * @n1: First input number
 * @n2: Second input number
 * @r: Buffer that store the result
 * @size_r: buffer size
 *
 * Return: Pointer to the result or 0 
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, k, l, m, n;

	for (i = 0; n1[i] != '\0'; i++)
		;
	for (j = 0; n2[j] != '\0'; j++)
		;

	if (i > size_r || j > size_r)
		return (0);

	r[size_r] = '\0';
	i--;
	j--;
	l = 0;

	for (k = size_r - 1; k >= 0; k--)
	{
		m = l;
		if (i >= 0)
			m += n1[i--] - '0';

		if (j >= 0)
			m += n2[j--] - '0';

		if (i < 0 && j < 0 && m == 0)
		{
			r[k] = '\0';
			return (&r[k + 1]);
		}

		l = m / 10;
		r[k] = m % 10 + '0';
	}

	if (l == 1 || r[0] != '0')
		return (0);

	return (r);
}
