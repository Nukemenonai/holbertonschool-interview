#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"


/**
* find_listint_loop - finds the loop in a linked list
* using the floyd agorithm
* @head: the pointer to the head of the linked list
*
* Return: pointer where loop starts or NULL if no loop
**/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *hare = NULL;
	listint_t *tortoise = NULL;

	if (!head)
		return (NULL);

	hare = head;
	tortoise = head;

	while (tortoise && hare && hare->next)
	{
		hare = (hare->next)->next;
		tortoise = tortoise->next;

		if (hare == tortoise)
		{
			tortoise = head;

			while(tortoise && hare)
			{
				if (tortoise == hare)
					return tortoise;
				tortoise = tortoise->next;
				hare = hare->next;
			}
		}
	}

	return (NULL);

}
