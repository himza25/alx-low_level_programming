#include "function_pointers.h"

/**
 * print_name - prints a name
 * @name: name of the person
 * @f: function pointer that takes a string as parameter
 *
 * Return: Nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
	f(name);
}
