#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_table = malloc(sizeof(shash_table_t));
	if (!new_table)
		return NULL;
	new_table->size = size;
	new_table->array = malloc(sizeof(shash_node_t *) * size);
	if (!new_table->array)
		return NULL;
	new_table->shead = NULL;
	new_table->stail = NULL;
	return new_table;
}

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = key_index((const unsigned char *)key, ht->size);
	shash_node_t *new_node = malloc(sizeof(shash_node_t));
	shash_node_t *current_node, *prev_node;

	if (!new_node)
		return 0;

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[index];
	new_node->sprev = NULL;
	new_node->snext = NULL;
	ht->array[index] = new_node;

	current_node = ht->shead;
	prev_node = NULL;

	while (current_node && strcmp(current_node->key, key) < 0)
	{
		prev_node = current_node;
		current_node = current_node->snext;
	}

	if (prev_node)
		prev_node->snext = new_node;
	else
		ht->shead = new_node;

	new_node->sprev = prev_node;
	new_node->snext = current_node;

	if (current_node)
		current_node->sprev = new_node;
	else
		ht->stail = new_node;

	return 1;
}

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index = key_index((const unsigned char *)key, ht->size);
	shash_node_t *current_node = ht->array[index];

	while (current_node)
	{
		if (strcmp(current_node->key, key) == 0)
			return current_node->value;
		current_node = current_node->next;
	}
	return NULL;
}

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current_node = ht->shead;
	printf("{");
	while (current_node)
	{
		printf("'%s': '%s'", current_node->key, current_node->value);
		current_node = current_node->snext;
		if (current_node)
			printf(", ");
	}
	printf("}\n");
}

void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *current_node, *next_node;

	for (i = 0; i < ht->size; ++i)
	{
		current_node = ht->array[i];
		while (current_node)
		{
			next_node = current_node->next;
			free(current_node->key);
			free(current_node->value);
			free(current_node);
			current_node = next_node;
		}
	}
	free(ht->array);
	free(ht);
}
