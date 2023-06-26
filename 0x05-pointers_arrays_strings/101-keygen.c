#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

/**
 * main - Generates random valid passwords for the program 101-crackme.
 *
 * Return: Always 0.
 */
int main(void)
{
	int i, sum, n;
	int password[100];

	srand(time(NULL));

	for (i = 0, sum = 0; sum < (2772 - 122); i++)
	{
		n = rand() % 94 + 33;
		password[i] = n;
		sum += n;
	}
	n = 2772 - sum;
	password[i] = n;

	for (i = 0; password[i]; i++)
	{
		_putchar(password[i]);
	}

	return (0);
}
