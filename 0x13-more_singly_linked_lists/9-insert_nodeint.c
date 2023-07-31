#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to the head of the list
 * @idx: index where the new node should be added
 * @n: data (integer) for the new node
 *
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new_node, *tmp;

	if (head == NULL)
		return (NULL);

	if (idx != 0)
	{
		tmp = *head;
		for (i = 0; i < idx - 1 && tmp != NULL; i++)
			tmp = tmp->next;

		if (tmp == NULL)
			return (NULL);
	}

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		new_node->next = tmp->next;
		tmp->next = new_node;
	}

	return (new_node);
}
