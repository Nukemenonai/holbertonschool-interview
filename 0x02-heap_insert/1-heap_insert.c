#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * create - creates a new node
 *
 * Return: 0 on success, error code on failure
 */

heap_t *create(int value)
{
	heap_t *new = malloc(sizeof(heap_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->left = NULL;
	new->right = NULL;
        return (new);
}

 /**
 * main - inserts a new node
 *
 * Return: 0 on success, error code on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = create(value);
	if (!new)
		return (NULL)
	heap_t *tmp = *root;

	if (*root = NULL)
	{
		root = new;
		return (new);
	}
	else
		first_av_ins(root, new);

	return (new);

}

 /**
 * first_av_ins- finds the first available node and inserts
 *
 * Return: the address to the last
 */

heap_t *first_av_ins( heap_t **root, heap_t *new_node)
{
	heap_t *tmp, *tmp2;
	size_t depthr = 0;

	if()
}
