#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#define SIZE 50

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s heap_t;

typedef struct Queue
{
	int size;
	int front, rear;
	heap_t **array;
} Queue;

void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *create(int value);
void swap(int *a, int *b);
Queue *createQueue(int size);
heap_t *getFront(Queue *queue);
heap_t *Dequeue(Queue *queue);
heap_t *insert(heap_t **root, int n, Queue *queue);
heap_t *heap_insert(heap_t **root, int value);


#endif /* _BINARY_TREES_H_ */
