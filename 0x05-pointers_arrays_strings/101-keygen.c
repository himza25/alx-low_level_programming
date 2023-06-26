#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 10
#define NUMBER_OF_CHARS 62

int main(void)
{
    char characters[NUMBER_OF_CHARS] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char password[LENGTH];
    int i;

    srand(time(NULL));

    for (i = 0; i < LENGTH - 1; i++)
    {
        password[i] = characters[rand() % NUMBER_OF_CHARS];
    }

    password[LENGTH - 1] = '\0';

    printf("%s\n", password);

    return (0);
}
