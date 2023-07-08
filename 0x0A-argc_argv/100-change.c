#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the minimum number of coins to make change.
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0 if successful, 1 if error
 */
int main(int argc, char *argv[])
{
	int change, quarters, dimes, nickels, twop, pennies;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	change = atoi(argv[1]);
	if (change < 0)
	{
		printf("0\n");
		return (0);
	}

	quarters = change / 25;
	change %= 25;
	dimes = change / 10;
	change %= 10;
	nickels = change / 5;
	change %= 5;
	twop = change / 2;
	change %= 2;
	pennies = change;

	printf("%d\n", quarters + dimes + nickels + twop + pennies);

	return (0);
}
