#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at index of a dlistint_t list.
 * @head: Double pointer to the head of the list.
 * @index: Index of the node that should be deleted, starts at 0.
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	while (current != NULL)
	{
		if (i == index)
		{
			if (current->prev)
				current->prev->next = current->next;
			else
				*head = current->next;

			if (current->next)
				current->next->prev = current->prev;

			free(current);
			return (1);
		}
		current = current->next;
		i++;
	}
	return (-1);
}
