#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer to the start of the list
 * @idx: index where the new node should be added, starting at 0
 * @n: data for the new node
 * 
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    unsigned int i;
    dlistint_t *new_node;
    dlistint_t *current;

    if (h == NULL)
        return (NULL);

    if (idx == 0)
        return (add_dnodeint(h, n));

    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);
    new_node->n = n;

    current = *h;
    for (i = 0; current != NULL && i < idx; i++)
        current = current->next;

    if (current == NULL && i == idx)
    {
        new_node->prev = NULL;
        new_node->next = NULL;
        *h = new_node;
        return (new_node);
    }

    if (current == NULL)
    {
        free(new_node);
        return (NULL);
    }

    new_node->prev = current->prev;
    new_node->next = current;
    if (current->prev != NULL)
        current->prev->next = new_node;
    else
        *h = new_node;
    current->prev = new_node;

    return (new_node);
}
