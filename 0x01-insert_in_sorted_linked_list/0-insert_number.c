#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a node in an ordered list.
 * @head: pointer to the head of the linked list
 * @number: the number to be inserted
 * Return: Always 0.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *tmp = *head;
	listint_t *tmp2;
	listint_t *new = malloc(sizeof(listint_t));

	if (new == NULL || !number )
		return NULL;
	new->n = number;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
		return (new);
	}
	if (tmp->n < number )
	{
		while (tmp != NULL && tmp->n < number)
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		tmp2->next = new;
		if (tmp != NULL)
			new->next = tmp;
	}
	else
	{
		new->next = tmp;
		*head = new;
	}
	return (new);
}
