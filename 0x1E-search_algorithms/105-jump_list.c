#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted singly linked list of integers
 *             using the Jump search algorithm.
 * @list: A pointer to the head of the singly linked list.
 * @size: The number of nodes in the list.
 * @value: The value to search for.
 *
 * Return: A pointer to the first node where value is located, or NULL if value
 *         is not present or list is NULL.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump_step = (size_t)sqrt(size);
	size_t step;
	listint_t *prev = list, *current = list;

	if (!list)
		return (NULL);

	/* Jumping through the list */
	while (current->index < size && current->n < value)
	{
		prev = current;
		for (step = 0; step < jump_step && current->next; step++)
			current = current->next;

		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
	}

	/* Linear search in the sublist */
	printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, current->index);
	while (prev && prev->index <= current->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);

		prev = prev->next;
	}

	return (NULL);
}
