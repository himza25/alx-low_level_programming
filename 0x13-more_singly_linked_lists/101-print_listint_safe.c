#include "lists.h"
#include <stdlib.h>

/**
 * find_list_length - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t find_list_length(const listint_t *head)
{
	const listint_t *slow, *fast;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	slow = head->next;
	fast = (head->next)->next;

	while (fast)
	{
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				nodes++;
				slow = slow->next;
				fast = fast->next;
			}

			slow = slow->next;
			while (slow != fast)
			{
				nodes++;
				slow = slow->next;
			}

			return (nodes);
		}

		slow = slow->next;
		fast = (fast->next)->next;
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

	nodes = find_list_length(head);

	if (nodes == 0)
	{
		while (head != NULL)
		{
			_putchar('[');
			print_address((unsigned long int)head);
			_putchar(']');
			print_int(head->n);
			_putchar('\n');
			head = head->next;
		}
	}

	else
	{
		for (index = 0; index < nodes; index++)
		{
			_putchar('[');
			print_address((unsigned long int)head);
			_putchar(']');
			print_int(head->n);
			_putchar('\n');
			head = head->next;
		}

		_putchar('-');
		_putchar('>');
		_putchar('[');
		print_address((unsigned long int)head);
		_putchar(']');
		print_int(head->n);
		_putchar('\n');
	}

	return (nodes);
}
