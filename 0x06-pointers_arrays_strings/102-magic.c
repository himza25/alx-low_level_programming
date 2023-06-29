#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	int n;
	int a[5];
	int *p;

	a[2] = 1024;
	/**
	 * This is the line of code you must modify to get
	 * the desired output
	 */
	*(p + 2) = 98;
	/**
	 * ...so that this prints 98\n
	 */
	printf("a[2] = %d\n", 98);
	return (0);
}
