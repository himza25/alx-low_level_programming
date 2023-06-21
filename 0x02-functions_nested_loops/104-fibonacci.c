#include "main.h"
#include <stdio.h>

/**
 * fib_split - split large Fibonacci numbers and print them
 * @a: first part of large Fibonacci number
 * @b: second part of large Fibonacci number
 * @n: Fibonacci sequence position
 */
void fib_split(unsigned long a, unsigned long b, int n)
{
	unsigned long s1, s2, s3;
	unsigned long p1, p2;
	unsigned long t1, t2;
	unsigned long carry = 0;

	p1 = a / 1000000000;
	p2 = a % 1000000000;
	s1 = b / 1000000000;
	s2 = b % 1000000000;

	while (n-- > 0)
	{
		t1 = s1;
		t2 = s2;
		s1 = p1;
		s2 = p2;
		if (t2 + s2 + carry > 999999999)
		{
			s3 = (t2 + s2 + carry) - 1000000000;
			p1 = s1 + t1 + 1;
		}
		else
		{
			s3 = t2 + s2 + carry;
			p1 = s1 + t1;
		}
		p2 = s3;

		carry = (s2 + t2) / 1000000000;

		printf(", %lu%010lu", p1, p2);
	}
	putchar('\n');
}

/**
 * main - Entry point, prints first 98 Fibonacci numbers
 * Return: Always 0
 */
int main(void)
{
	unsigned long count, i = 1, j = 2, sum;

	printf("%lu, %lu", i, j);
	for (count = 2; count < 60; count++)
	{
		sum = i + j;
		printf(", %lu", sum);
		i = j;
		j = sum;
	}

	fib_split(i, j, 98 - 60);

	return (0);
}
