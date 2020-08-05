#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * rec_lookup - looks recursively for the first available
 * @node: the double pointer to the root node
 * the value to insert to node
 * Return: 0 on success, error code on failure
 */
heap_t *rec_lookup(heap_t *node)
{
	if (node->left != NULL || node->right != NULL)
		rec_lookup(node->left), rec_lookup(node->right);
	else
		return (node);
	return (node);
}

/**
 * insert_first - creates a new node
 * @node: the double pointer to the root node
 * the value to insert to node
 * Return: 0 on success, error code on failure
 */

int insert_first(heap_t *node)
{
	int nnodesr = 0, nnodesl = 0;

	if (node->left != NULL)
		nnodesl += insert_first(node->left);
	if (node->right != NULL)
		nnodesr += insert_first(node->right);
	return (nnodesl <= nnodesr ? 0 : 1);
}

/**
 * heap_insert - creates a new node
 * @root: the double pointer to the root node
 * @value: the value to insert to node
 * Return: 0 on success, error code on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	int o;
	heap_t *res;
	heap_t *get_f;

	res = malloc(sizeof(heap_t));
	res->n = value;
	res->left = res->right = NULL;
	if (!res)
		return (NULL);
	if (!*root)
	{
		*root = res;
		return (res);
	}
	else
	{
		if ((*root)->left == NULL)
		{
			(*root)->left = res;
			return (res);
		}
		else if ((*root)->right == NULL)
		{
			(*root)->right = res;
			return (res);
		}
		else
		{
			o = insert_first(*root);
			if (o == 0)
				get_f = rec_lookup((*root)->left);
			else
				get_f = rec_lookup((*root)->left);
			if (get_f->left == NULL)
				get_f->left = res;
			else if (get_f->right == NULL)
				get_f->right = res;
		}
	}
	return (res);
}
