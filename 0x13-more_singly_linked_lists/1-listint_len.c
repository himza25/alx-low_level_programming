#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked listint_t list
 * @h: pointer to the start of the list
 *
 * Return: number of nodes in the list
 */
size_t listint_len(const listint_t *h)
{
	const listint_t *current;
	size_t count = 0;

	current = h;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return (count);
}
