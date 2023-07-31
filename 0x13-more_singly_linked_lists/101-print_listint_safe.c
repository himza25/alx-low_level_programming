#include "lists.h"
#include <stdio.h>

size_t find_loop_count(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * find_loop_count - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t find_loop_count(const listint_t *head)
{
	const listint_t *slow_pointer, *fast_pointer;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	slow_pointer = head->next;
	fast_pointer = (head->next)->next;

	while (fast_pointer)
	{
		if (slow_pointer == fast_pointer)
		{
			slow_pointer = head;
			while (slow_pointer != fast_pointer)
			{
				nodes++;
				slow_pointer = slow_pointer->next;
				fast_pointer = fast_pointer->next;
			}

			slow_pointer = slow_pointer->next;
			while (slow_pointer != fast_pointer)
			{
				nodes++;
				slow_pointer = slow_pointer->next;
			}

			return (nodes);
		}

		slow_pointer = slow_pointer->next;
		fast_pointer = (fast_pointer->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes, index = 0;

	nodes = find_loop_count(head);

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
		for (index = 0; index < nodes; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nodes);
}
