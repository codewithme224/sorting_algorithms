#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * size_t - the number of elements in an array
 * @array: array to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_helper(array, 0, (int)size - 1, size);
}


/**
 * quick_sort_helper - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * size_t - the number of elements in an array
 * @array: array to sort
 * @low: low index
 * @high: high index
 * @size: size of array
 */

void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pivots;

	if (low < high)
	{
		pivots = partition(array, low, high, size);
		quick_sort_helper(array, low, pivots - 1, size);
		quick_sort_helper(array, pivots + 1, high, size);
	}
}


/**
 * partition - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * size_t - the number of elements in an array
 * @array: array to sort
 * @low: low index
 * @high: high index
 * @size: size of array
 * Return: pivot
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			if (array[i] != array[j])
				print_array(array, size);
			i++;
		}
	}
	temp = array[i];
	array[i] = array[high];
	array[high] = temp;
	if (array[i] != array[high])
		print_array(array, size);
	return (i);
}
