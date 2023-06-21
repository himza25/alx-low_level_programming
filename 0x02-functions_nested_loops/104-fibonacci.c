#include "main.h"
#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long count, i = 1, j = 2, sum;
	unsigned long split1, split2, split3;
	unsigned long split_a, split_b, split_c;

	printf("%lu, %lu, ", i, j);
	for (count = 2; count < 59; count++)
	{
		sum = i + j;
		printf("%lu, ", sum);
		i = j;
		j = sum;
	}

	split_a = i / 1000000000;
	split_b = i % 1000000000;
	split_c = j / 1000000000;
	split1 = j % 1000000000;

	for (; count < 98; count++)
	{
		split2 = split_a;
		split3 = split_b;
		split_a = split_c;
		split_b = split1;
		if (split_b + split3 > 999999999)
		{
			split1 = (split_b + split3) - 1000000000;
			split_c = split_a + split2 + 1;
		}
		else
		{
			split1 = split_b + split3;
			split_c = split_a + split2;
		}

		if (count != 97)
			printf("%lu%lu, ", split_c, split1);
		else
			printf("%lu%lu\n", split_c, split1);
	}
	return (0);
}
