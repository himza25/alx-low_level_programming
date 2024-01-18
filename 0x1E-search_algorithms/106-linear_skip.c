#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 * Return: Pointer to first node where value is located, or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *last_node;

	if (!list)
		return (NULL);

	node = traverse_express(list, value, &last_node);
	if (!node)
		return (NULL);

	/* Linear search in the range */
	while (node != last_node && node->n < value)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       node->index, node->n);
		node = node->next;
	}
	printf("Value checked at index [%lu] = [%i]\n",
	       node->index, node->n);

	if (node == last_node)
		return (NULL);
	return (node);
}

/**
 * traverse_express - Traverses the express lane of the skip list
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 * @last_node: Pointer to store the last node of the express lane
 * Return: Pointer to the node where express lane traversal stopped
 */
skiplist_t *traverse_express(skiplist_t *list,
		int value, skiplist_t **last_node)
{
	skiplist_t *node = list;

	/* Traverse the express lane */
	while (node->express && node->express->n < value)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       node->express->index, node->express->n);
		node = node->express;
	}
	*last_node = node;
	while ((*last_node)->next && (*last_node)->next != (*last_node)->express)
		*last_node = (*last_node)->next;

	/* Determine the range to search */
	if (node->express)
	{
		printf("Value checked at index [%lu] = [%i]\n",
		       node->express->index, node->express->n);
		printf("Value found between indexes [%lu] and [%lu]\n",
		       node->index, node->express->index);
	}
	else
		printf("Value found between indexes [%lu] and [%lu]\n",
		       node->index, (*last_node)->index);

	return (node);
}
