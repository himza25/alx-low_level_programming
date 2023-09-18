#!/bin/bash

# Create a dynamic library called liball.so from all the .c files in the current directory
gcc -Wall -Werror -Wextra -pedantic -fPIC -c *.c
gcc -Wall -Werror -Wextra -pedantic -shared -o liball.so *.o

# Clean up
rm *.o
