#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 */

void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;
	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;
	merge_sort_helper(array, 0, size - 1, tmp);
	free(tmp);
}

/**
 * merge_sort_helper - sorts an array of integers in ascending order
 * @array: array to sort
 * @lo: lowest index of partition to sort
 * @hi: highest index of partition to sort
 * @tmp: temp array to store sorted partition
 */

void merge_sort_helper(int *array, int lo, int hi, int *tmp)
{
	int mid;

	if (lo < hi)
	{
		mid = (lo + hi) / 2;
		merge_sort_helper(array, lo, mid, tmp);
		merge_sort_helper(array, mid + 1, hi, tmp);
		merge(array, lo, mid, hi, tmp);
	}
}

/**
 * merge - merges two sorted sub-arrays
 * @array: array to sort
 * @lo: lowest index of left partition
 * @mid: highest index of left partition
 * @hi: highest index of right partition
 * @tmp: temp array to store sorted partition
 */

void merge(int *array, int lo, int mid, int hi, int *tmp)
{
	int i, j, k;

	printf("Merging...\n[left]: ");
	print_array(array + lo, mid - lo + 1);
	printf("[right]: ");
	print_array(array + mid + 1, hi - mid);

	i = lo;
	j = mid + 1;
	k = lo;

	while (i <= mid && j <= hi)
	{
		if (array[i] < array[j])
			tmp[k++] = array[i++];
		else
			tmp[k++] = array[j++];
	}

	while (i <= hi)
		tmp[k++] = array[i++];
	while (j <= hi)
		tmp[k++] = array[j++];
	for (i = lo; i <= hi; i++)
		array[i] = tmp[i];
	printf("[Done]: ");
	print_array(array + lo, hi - lo + 1);
}
