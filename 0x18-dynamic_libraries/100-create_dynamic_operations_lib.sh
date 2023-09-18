#!/bin/bash

gcc -Wall -Werror -Wextra -pedantic -fPIC -c 100-operations.c
gcc -Wall -Werror -Wextra -pedantic -shared -o 100-operations.so 100-operations.o
