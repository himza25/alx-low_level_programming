#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates and prints keys for crackme5 executable.
 * @argc: The count of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	char key[7], *index;
	int length = strlen(argv[1]), i, temp;

	index = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	temp = (length ^ 59) & 63;
	key[0] = index[temp];

	temp = 0;
	for (i = 0; i < length; i++)
		temp += argv[1][i];
	key[1] = index[(temp ^ 79) & 63];

	temp = 1;
	for (i = 0; i < length; i++)
		temp *= argv[1][i];
	key[2] = index[(temp ^ 85) & 63];

	temp = 0;
	for (i = 0; i < length; i++)
	{
		if (argv[1][i] > temp)
			temp = argv[1][i];
	}
	srand(temp ^ 14);
	key[3] = index[rand() & 63];

	temp = 0;
	for (i = 0; i < length; i++)
		temp += (argv[1][i] * argv[1][i]);
	key[4] = index[(temp ^ 239) & 63];

	for (i = 0; i < argv[1][0]; i++)
		temp = rand();
	key[5] = index[(temp ^ 229) & 63];

	key[6] = '\0';
	printf("%s", key);
	return (0);
}
