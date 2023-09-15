#include "lists.h"

/**
 * sum_dlistint - computes the sum of all the data (n) in a dlistint_t list
 *
 * @head: pointer to the head of the list
 * Return: the total sum of the data, or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int total = 0;

	while (head)
	{
		total += head->n;
		head = head->next;
	}

	return (total);
}
