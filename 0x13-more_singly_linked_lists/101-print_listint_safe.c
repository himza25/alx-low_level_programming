#include "lists.h"
#include <stdio.h>

size_t find_list_length(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * find_list_length - Counts the number of unique nodes
 * in a listint_t linked list.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: If the list is looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t find_list_length(const listint_t *head)
{
	const listint_t *current = head;
	const listint_t *check;
	size_t nodes = 0;

	while (current != NULL)
	{
		nodes++;
		check = head;

		while (check != current)
		{
			if (check == current->next)
			{
				return (nodes);
			}
			check = check->next;
		}

		current = current->next;
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

	nodes = looped_listint_len(head);

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
