#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list,
 * and returns the head node’s data (n).
 * @head: double pointer to the head of the listint_t list
 *
 * Return: data in the head node
 */
int pop_listint(listint_t **head)
{
	int n;
	listint_t *temp;

	/* Check if the list is empty */
	if (*head == NULL)
		return (0);

	/* Get data from the head */
	n = (*head)->n;

	/* Move the head to point to the next node */
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (n);
}
