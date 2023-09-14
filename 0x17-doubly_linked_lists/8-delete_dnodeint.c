#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at a specific index
 * @head: double pointer to the start of the list
 * @index: index of the node that should be deleted, starting at 0
 * 
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    unsigned int i;
    dlistint_t *current;

    if (head == NULL || *head == NULL)
        return (-1);

    current = *head;
    for (i = 0; current != NULL && i < index; i++)
        current = current->next;

    if (current == NULL)
        return (-1);

    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        *head = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
    return (1);
}
