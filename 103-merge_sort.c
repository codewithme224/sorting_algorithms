#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 */

void merge_sort(int *array, size_t size)
{
	size_t mid = 0, i;
	int left[1000];
	int right[1000];

	if (!array)
		return;

	if (size < 2)
		return;

	mid = size / 2;

	for (i = 0; i < mid; i++)
		left[i] = array[i];

	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, right, size);
}

/**
 * merge - merges two sorted sub-arrays
 * @array: array to sort
 * @size: size of the array
 * @lo: lowest index of left partition
 * @hi: highest index of right partition
 */

void merge(int *array, int *lo, int *hi, size_t size)
{
	int i = 0, j = 0, k = 0;
	int size_lo, size_hi;

	size_lo = size / 2;
	size_hi = size - size_lo;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(lo, size_lo);
	printf("[right]: ");
	print_array(hi, size_hi);

	while (i < size_lo && j < size_hi)
	{
		if (lo[i] < hi[j])
			array[k++] = lo[i++];
		else
			array[k++] = hi[j++];
	}

	while (i < size_lo)
		array[k++] = lo[i++];

	while (j < size_hi)
		array[k++] = hi[j++];
	printf("[Done]: ");
	print_array(array, size);
}
