#include "lists.h"
#include <stdio.h>

/**
 * print_listint - prints all elements of a listint_t list
 * @h: pointer to the start of the list
 * 
 * Return: number of nodes in the list
 */
size_t print_listint(const listint_t *h)
{
	const listint_t *current;
	size_t count = 0;

	current = h;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		count++;
		current = current->next;
	}

	return count;
}
