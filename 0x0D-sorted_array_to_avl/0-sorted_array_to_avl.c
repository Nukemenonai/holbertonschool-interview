#include <stdlib.h>
#include "binary_trees.h"


/**
* new_node - creates a new node in a binary tree
* @parent: *pointer to its parent node
* @value: the value that the node contains
* Return: node. NULL on failure
*/

binary_tree_t *new_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	new = malloc(sizeof(binary_tree_t));

	if (!new)
		return (NULL);

	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	new->n = value;

	return (new);
}

/**
* insert - function to sort insert a node
* @array: pointer to the array to be converted
* @min: lower limit
* @max: upper limit
* Return: pointer to the root node of the AVL tree
*/

avl_t *insert(int *array, int min, int max)
{
	int half;
	avl_t *tree;

	if (min > max)
		return (NULL);

	half = (max + min) / 2;

	tree = new_node(NULL, array[half]);
	if (!tree)
		return (NULL);

	tree->left = insert(array, min, half - 1);
	tree->right = insert(array, half + 1, max);

	if (tree->left)
		tree->left->parent = tree;
	if (tree->right)
		tree->right->parent = tree;

	return (tree);
}

/**
* sorted_array_to_avl - builds an AVL tree from an array
* @array: pointer to the first element of the array
* @size: size of the array
* Return: the pointer to the root node of the AVL tree or NULL
*/

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *rt = NULL;

	if (!array)
		return (NULL);
	if (size < 1)
		return (NULL);

	rt = insert(array, 0, size - 1);

	return (rt);
}