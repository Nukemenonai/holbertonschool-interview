#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

Queue *queue = createQueue(SIZE);

/**
 * create - creates a new node
 * @value: number to be inserted
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
 * swap - creates a new node
 * @a: first pointer
 * @b: second pointer
 * Return: 0 on success, error code on failure
 */

void swap(int *a, int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

 /**
 * createQueue - inserts a new node
 * @size: size of the queue
 * Return: 0 on success, error code on failure
 */

Queue *createQueue(int size)
{
	int i;
	struct Queue *queue = (struct Queue *) malloc(sizeof(struct Queue));

	queue->front = queue->rear = -1;
	queue->size = size;
	queue->array = (heap_t **)malloc(queue->size * sizeof(heap_t *));
	for (i = 0; i < size; ++i)
		queue->array[i] = NULL;
	return (queue);
}


/**
 * getFront - creates a new node
 * @queue: the queue to insert to
 * Return: 0 on success, error code on failure
 */

heap_t *getFront(Queue *queue)
{
	return (queue->array[queue->front]);
}


/**
 * Enqueue - creates a new node
 * @root: the pointer to the root node
 * @queue: the queue to use
 * Return: 0 on success, error code on failure
 */


void Enqueue(heap_t *root, Queue *queue)
{
	if (queue->rear == queue->size - 1)
		return;
	queue->array[++queue->rear] = root;
	if (queue->front == -1)
		++queue->front;
}


/**
 * Dequeue - creates a new node
 * @queue: the queue to use
 * Return: 0 on success, error code on failure
 */


heap_t *Dequeue(Queue *queue)
{
	if (queue->front == -1)
		return (NULL);

	heap_t *temp = queue->array[queue->front];

	if (queue->front == queue->rear)
		queue->front = queue->rear = -1;
	else
		++queue->front;
	return (temp);
}


/**
 * insert - creates a new node
 * @root: the double pointer to the variable to use
 * @queue: the queue to use
 * Return: 0 on success, error code on failure
 */

heap_t *insert(heap_t **root, int n, Queue *queue)
{
	heap_t *new = create(n);
	heap_t *front;

	if (!new)
		return (NULL);

	if (!*root)
		*root = new;
	else
	{
		printf("me toco buscar nodo en el q\n");
		front = getFront(queue);
		if (!front->left)
		{
			front->left = new;
		}


		else if (!front->right)
		{
			front->right = new;
		}

		if (front->left && front->right)
			Dequeue(queue);

	}
	Enqueue(new, queue);
	return (new);
}


/**
 * heap_insert - creates a new node
 * @root: the double pointer to the root node
 * @value: the value to insert to node
 * Return: 0 on success, error code on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *res;

	res = insert(root, value, queue);
	return (res);
}
