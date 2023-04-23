#include "sort.h"

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_hoare_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_hoare_helper - sorts an array of integers in ascending order
 * @array: array to sort
 * @lo: low index
 * @hi: high index
 * @size: size of array
 */

void quick_sort_hoare_helper(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition_hoare(array, lo, hi, size);
		quick_sort_hoare_helper(array, lo, p, size);
		quick_sort_hoare_helper(array, p + 1, hi, size);
	}
}

/**
 * partition_hoare - partitions an array of integers
 * @array: array to sort
 * @lo: low index
 * @hi: high index
 * @size: size of array
 * Return: partition index
 */

int partition_hoare(int *array, int lo, int hi, size_t size)
{
	int pivot, tmp;

	pivot = array[hi];

	while (lo <= hi)
	{
		while (array[lo] < pivot)
			lo++;
		while (array[hi] > pivot)
			hi--;
		if (lo <= hi)
		{
			if (lo != hi)
			{
				tmp = array[lo];
				array[lo] = array[hi];
				array[hi] = tmp;
				print_array(array, size);
			}
			lo++;
			hi--;
		}
	}
	return (hi);

}
