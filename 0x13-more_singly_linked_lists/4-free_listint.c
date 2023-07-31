#include <stdlib.h>
#include "lists.h"

/**
 * free_listint - Frees a listint_t list
 * @head: The list
 *
 * Return: Nothing
 */
void free_listint(listint_t *head)
{
	listint_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
