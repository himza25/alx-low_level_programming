#include "lists.h"
#include <stdio.h>

size_t count_unique_nodes_in_loop(const listint_t *head);
size_t print_listint_safely(const listint_t *head);

/**
 * count_unique_nodes_in_loop - Counts the unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t count_unique_nodes_in_loop(const listint_t *head)
{
	const listint_t *slow_pointer, *fast_pointer;
	size_t node_count = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	slow_pointer = head->next;
	fast_pointer = (head->next)->next;

	while (fast_pointer != NULL)
	{
		if (slow_pointer == fast_pointer)
		{
			slow_pointer = head;
			while (slow_pointer != fast_pointer)
			{
				node_count++;
				slow_pointer = slow_pointer->next;
				fast_pointer = fast_pointer->next;
			}

			slow_pointer = slow_pointer->next;
			while (slow_pointer != fast_pointer)
			{
				node_count++;
				slow_pointer = slow_pointer->next;
			}

			return (node_count);
		}

		slow_pointer = slow_pointer->next;
		fast_pointer = fast_pointer->next ?
		(fast_pointer->next)->next : fast_pointer->next;
	}

	return (0);
}

/**
 * print_listint_safely - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safely(const listint_t *head)
{
	size_t nodes, idx = 0;

	nodes = count_unique_nodes_in_loop(head);

	if (nodes == 0)
	{
		for (; head != NULL; nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (idx = 0; idx < nodes; idx++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nodes);
}
