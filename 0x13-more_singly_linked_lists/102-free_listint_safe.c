#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - frees a listint_t list safely.
 * @h: double pointer to the start of the list.
 *
 * Return: the size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	size_t num = 0;
	listint_t *temp;
	long int diff;

	if (!h || *h == NULL)
		return (0);

	while (*h)
	{
		diff = *h - (*h)->next;
		if (diff > 0)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
			num++;
		}
		else
		{
			free(*h);
			*h = NULL;
			num++;
			break;
		}
	}

	*h = NULL;

	return (num);
}
