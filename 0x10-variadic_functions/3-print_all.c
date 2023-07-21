#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_char - prints a char.
 * @arg: list of argument.
 * Return: void
 */
void print_char(va_list arg)
{
	printf("%c", va_arg(arg, int));
}

/**
 * print_integer - prints an integer.
 * @arg: list of argument.
 * Return: void
 */
void print_integer(va_list arg)
{
	printf("%d", va_arg(arg, int));
}

/**
 * print_float - prints a float.
 * @arg: list of argument.
 * Return: void
 */
void print_float(va_list arg)
{
	printf("%f", va_arg(arg, double));
}

/**
 * print_string - prints a string.
 * @arg: list of argument.
 * Return: void
 */
void print_string(va_list arg)
{
	char *str;

	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(nil)";
	printf("%s", str);
}

/**
 * print_all - prints anything.
 * @format: list of types of arguments.
 * Return: void
 */
void print_all(const char * const format, ...)
{
	printer_t printers[] = {
		{"c", print_char},
		{"i", print_integer},
		{"f", print_float},
		{"s", print_string},
		{NULL, NULL}
	};
	va_list arg;
	int i = 0, j;
	char *separator = "";

	va_start(arg, format);
	while (format != NULL && format[i] != '\0')
	{
		j = 0;
		while (printers[j].symbol != NULL)
		{
			if (format[i] == *(printers[j].symbol))
			{
				printf("%s", separator);
				printers[j].print(arg);
				separator = ", ";
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(arg);
}
