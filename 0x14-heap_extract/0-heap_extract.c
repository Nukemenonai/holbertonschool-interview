#include "binary_trees.h"


/**
 * height - give the heigh of the binary tree
 * @tree: tree to measure
 * Return: number with the heigh of the tree
 **/

size_t height(const heap_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (0);

	left = height(tree->left) + 1;
	right = height(tree->right) + 1;

	if (left >= right)
		return (left);
	else
		return (right);
}

/**
 * recursion - go until the deepest node
 * @tree: tree to go through
 * @node: pointer to point to the deepest node
 * @height: height of the tree
 * @level: actual level of the tree
 **/
void recursion(heap_t *tree, heap_t **node, size_t height, size_t level)
{
	if (!tree)
		return;

	if (height == level)
		*node = tree;

	level++;

	if (tree->left)
		recursion(tree->left, node, height, level);

	if (tree->right)
		recursion(tree->right, node, height, level);
}

/**
 * replace - change values through nodes
 * @tree: tree to go through
 * @node: deepest node
 * @extracted_value: value to extract
 * Return: extracted value after free the node
 **/
int replace(heap_t **tree, heap_t **node, int extracted_value)
{
	heap_t *aux;
	int value;

	aux = *tree;

	while (aux->left || aux->right)
	{
		if (!aux->right || aux->left->n > aux->right->n)
		{
			value = aux->n;
			aux->n = aux->left->n;
			aux->left->n = value;
			aux = aux->left;
		}
		else if (!aux->left || aux->left->n < aux->right->n)
		{
			value = aux->n;
			aux->n = aux->right->n;
			aux->right->n = value;
			aux = aux->right;
		}
	}
	aux->n = (*node)->n;
	if ((*node)->parent->right)
		(*node)->parent->right = NULL;
	else
		(*node)->parent->left = NULL;
	free(*node);
	return (extracted_value);
}

/**
 * heap_extract - extracts the root node
 * @root: pointer to the tree
 * Return: value of extracted node
 **/

int heap_extract(heap_t **root)
{
	int e_value, res;
	size_t level, h;
	heap_t *aux, *node = NULL;

	if (!root || !*root)
		return (0);
	aux = *root;
	e_value = aux->n;
	level = 0;
	if (aux->left == NULL && aux->right == NULL)
	{
		*root = NULL;
		free(aux);
		return (e_value);
	}
	h = height(aux);
	recursion(aux, &node, h, level);
	res = replace(&aux, &node, e_value);
	return (res);
}
