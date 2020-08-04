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
 * create - creates a new node
 *
 * Return: 0 on success, error code on failure
 */

void swap(int *a, int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

 /**
 * main - inserts a new node
 *
 * Return: 0 on success, error code on failure
 */

Queue *createQueue(int size)
{
	int i;
	struct Queue* queue = (struct Queue*) malloc(sizeof( struct Queue ));

	queue->front = queue->rear = -1;
	queue->size = size;
	queue->array = (heap_t **) malloc
		(queue->size * sizeof(heap_t));
	for (i = 0; i < size; ++i)
		queue->array[i] = NULL;
	return (queue);
}

heap_t *getFront(Queue *queue)
{
	printf("entre a la función de getfront\n");
	return (queue->array[queue->front]);
}

void Enqueue(heap_t *root, Queue *queue)
{
	printf("entre a la función de enqueue, mi root es %d\n", root->n);
	if (queue->rear == queue->size -1)
		return;
	queue->array[++queue->rear] = root;
	if (queue->front == -1)
		++queue->front;
}

heap_t *Dequeue(Queue *queue)
{
	if (queue->front == -1)
		return NULL;

	heap_t *temp = queue->array[queue->front];

	if (queue->front == queue->rear)
		queue->front = queue->rear = -1;
	else
		++queue->front;
	return (temp);
}

heap_t *insert(heap_t **root, int n, Queue *queue)
{
	printf("entré a insertar \n");
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
		printf("recibi el nodo frontal %d\n", front->n);
		if (!front->left)
		{
			front->left = new;
			printf("asigne al hijo izq");
		}


		else if (!front->right)
		{
			front->right = new;
			printf("asigne al hijo derecho");
		}

		if (front->left && front->right)
			Dequeue(queue);

	}
        Enqueue(new, queue);

	return (new);
}

heap_t *heap_insert(heap_t **root, int value)
{
	printf("entré \n");
	heap_t *res;
	Queue *queue = createQueue(SIZE);
	res = insert(root, value, queue);
	printf("el valor de res es %d\n", res->n);
	return (res);
}
