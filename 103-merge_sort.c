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
 * @lo: lowest index of left partition
 * @mid: highest index of left partition
 * @hi: highest index of right partition
 * @tmp: temp array to store sorted partition
 */

void merge(int *array, int *l, int *r, size_t size)
{
	int i = 0, j = 0, k = 0;
	int size_l, size_r;

	size_l = size / 2;
	size_r = size - size_l;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(l, size_l);
	printf("[right]: ");
	print_array(r, size_r);

	while (i < size_l && j < size_r)
	{
		if (l[i] < r[j])
			array[k++] = l[i++];
		else
			array[k++] = r[j++];
	}

	while (i < size_l)
		array[k++] = l[i++];

	while (j < size_r)
		array[k++] = r[j++];
	printf("[Done]: ");
	print_array(array, size);
}
