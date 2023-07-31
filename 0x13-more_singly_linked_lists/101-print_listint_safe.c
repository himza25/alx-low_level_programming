#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow, *fast;
	size_t nodes = 0;

	if (!head)
		exit(98);

	slow = head;
	fast = head->next;

	while (fast && fast->next)
	{
		if (slow == fast)
		{
			printf("-> [%p] %d\n", (void *)slow, slow->n);
			return (nodes);
		}

		slow = slow->next;
		fast = fast->next->next;
		nodes++;
	}

	slow = head;
	while (slow)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		slow = slow->next;
		nodes++;
	}

	return (nodes);
}
