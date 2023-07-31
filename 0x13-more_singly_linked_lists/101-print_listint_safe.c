#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to head of the list
 * Return: the number 0
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t n = 0;
	const listint_t *current = head;

	while (current != NULL)
	{
		printf("[%p] %d\n", current, current->n);
		current = current->next;
		n++;
	}

	return (n);
}
	int main(void)
{
	listint_t *head;
	listint_t *node;

	head = NULL;
	node = malloc(sizeof(listint_t));
	node->n = 0;
	node->next = NULL;
	head = node;

	node = malloc(sizeof(listint_t));
	node->n = 1;
	node->next = NULL;
	head->next = node;

	print_listint_safe(head);

	return (0);
}
