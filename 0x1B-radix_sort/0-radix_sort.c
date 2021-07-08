#include <stdlib.h>
#include "sort.h"

/**
* maxNum - finds the biggest number in an array
*
* @array: the pointer to the array to be evaluated
* @size: the size of the array
*
* Return: the biggest element in the array
*/
int maxNum(int *array, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
* auxSort - auxiliary function to sort the array
*
* @array: the array to be soorted
* @size: the size of the array
* @lsd: less significant digit
*/

void auxSort(int *array, int size, int lsd)
{
	int *output, i;
	int auxArray[10] = {0};

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	for (i = 0; i < size; i++)
		auxArray[(array[i] / lsd) % 10]++;

	for (i = 1; i < 10; i++)
		auxArray[i] += auxArray[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[auxArray[(array[i] / lsd) % 10] - 1] = array[i];
		auxArray[(array[i] / lsd) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);

}
/**
 * radix_sort - sorts an array of integers in ascending order
 * using the LSD Radix sort algorithm
 *
 * @array: array of data to be sorted
 * @size: size of the data array
 *
 * Return: None
*/

void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (size < 2)
		return;

	max = maxNum(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		auxSort(array, size, exp);
		print_array(array, size);
	}
}