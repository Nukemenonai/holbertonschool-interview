#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 if not palindrome else 1
 */

int palindrome(listint_t **head, int len)
{
	int i, j;
	int arr[len + 1];
	listint_t *tmp = *head;

	if (!*head || (*head)->next == NULL)
		return (1);

	i = 0;
	while (tmp != NULL)
	{
		arr[i] = tmp->n;
		tmp = tmp->next;
		i++;
	}
	arr[i] = '\0';

	for (i=0, j=(len - 1); i<=(len/2); i++, j--)
	{
		if (arr[i] != arr[j])
			return (0);
	}
	return (1);
}

/**
 * is_palindrome - checks if linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 if not palindrome else 1
 */

int is_palindrome(listint_t **head)
{
	int len = 0;
	listint_t *tmp = *head;

	while (tmp != NULL)
	{
		tmp = tmp->next;
		len ++;
	}
	int res = palindrome(head, len);

	return (res);
}
