#include "search.h"

/**
* linear-skip - searches for a value in a sorted skip list
* @list: pointer to the head of of the skip list
* @value: the value to look for
*
* Return :a pointer to the first nod where value is located 
*/

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *pos = list;
	skiplist_t *min = list;
	size_t i;

	if (!list)
		return (NULL);

	while (pos && pos->next && (pos->n) < value)
	{
		min = pos;
		if (pos->express)
		{
			pos = pos->express;
			printf("Value checked at index [%lu] = [%d]\n",
				pos->index, pos->n);
		}
		else
			while(pos->next)
				pos = pos->next;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
		min->index, pos->index);
	
	for (i = pos->index;
		i <= (pos->index) && (min->n <= value);
		i++, min = min->next)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		i, min->n);
		if (min && (min->n) == value)
			return (min);
	}
	if (min)
		printf("Value checked at index [%lu] = [%d]\n",
		i, min->n);


	return (NULL);
}