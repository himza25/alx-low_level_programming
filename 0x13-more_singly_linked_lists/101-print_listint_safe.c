#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - prints all elements in a linked list
 * @head: pointer to the head of the list
 * Return: the number of nodes
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *slow_p = head, *fast_p = head;

	if (!head)
		exit(98);

	while (slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p  = fast_p->next->next;
		if (slow_p == fast_p)
		{
			const listint_t *start = head;

			while (start != slow_p)
			{
				printf("[%p] %d\n", (void *)start, start->n);
				start = start->next;
				count++;
			}

			do {
				printf("[%p] %d\n", (void *)slow_p, slow_p->n);
				slow_p = slow_p->next;
				count++;
			} while (slow_p != fast_p);
			printf("-> [%p] %d\n", (void *)slow_p, slow_p->n);

			return (count);
		}
	}

	while (head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		count++;
	}

	return (count);
}
