#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a skip list with sorted values
 * @list: Head of the skip list to search in
 * @value: Value to search for
 * Return: Pointer to the first node where the value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current_node, *last_express;

	if (!list)
		return (NULL);

	current_node = list;
	/* Traverse express lane to find the block */
	while (current_node->express && current_node->express->n < value)
	{
		printf("Value checked at index [%lu] = [%i]\n",
			   current_node->express->index, current_node->express->n);
		current_node = current_node->express;
	}

	/* Find the last node in the current express block */
	last_express = current_node;
	while (last_express->next && last_express->next != last_express->express)
		last_express = last_express->next;

	/* Determine the search range */
	printf("Value found between indexes [%lu] and [%lu]\n",
			current_node->index,
			current_node->express ? current_node->express->index : last_express->index);

	/* Perform linear search in the range */
	while (current_node != last_express->next && current_node->n < value)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		current_node->index, current_node->n);
		current_node = current_node->next;
	}

	/* Check if the current node is the target value */
	printf("Value checked at index [%lu] = [%i]\n",
		   current_node->index, current_node->n);
	if (current_node->n != value)
		return (NULL);

	return (current_node);
}
