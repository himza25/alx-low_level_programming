#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted list of integers using
 *             the Jump search algorithm.
 * @list: Pointer to the head of the list to search in.
 * @size: Number of nodes in the list.
 * @value: Value to search for.
 * Return: Pointer to the first node where value is located or NULL.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump_step = (size_t)sqrt(size);
	listint_t *prev = list, *current = list;
	size_t i;

	if (!list)
		return (NULL);

	/* Jumping through the list */
	for (i = 0; i < size && current->n < value; i += jump_step)
	{
		prev = current;
		for (size_t j = 0; j < jump_step && current->next; j++)
			current = current->next;

		printf("Value checked at index [%lu] = [%d]\n",
		       current->index, current->n);
	}

	/* Linear search in the sublist */
	printf("Value found between indexes [%lu] and [%lu]\n",
	       prev->index, current->index);
	while (prev && prev->index <= current->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       prev->index, prev->n);
		if (prev->n == value)
			return (prev);

		prev = prev->next;
	}

	return (NULL);
}
