#include "main.h"
#include <stdio.h>

/**
 * fib_split - split large Fibonacci numbers and print them
 * @a: first part of large Fibonacci number
 * @b: second part of large Fibonacci number
 * @n: Fibonacci sequence position
 */
void fib_split(unsigned int a, unsigned int b, int n)
{
    unsigned int s1, s2, s3;
    unsigned int p1, p2;
    unsigned int t1, t2;
    unsigned int carry = 0;

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

        printf(", %u%010u", p1, p2);
    }
    putchar('\n');
}

/**
 * main - Entry point, prints first 98 Fibonacci numbers
 * Return: Always 0
 */
int main(void)
{
    unsigned int count, i = 1, j = 2, sum;

    printf("%u, %u", i, j);
    for (count = 2; count < 60; count++)
    {
        sum = i + j;
        printf(", %u", sum);
        i = j;
        j = sum;
    }

    fib_split(i, j, 98 - 60);

    return (0);
}
