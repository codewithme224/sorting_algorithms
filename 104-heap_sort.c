#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 */

void heap_sort(int *array, size_t size)
{
	int i, tmp;

	if (!array || size < 2)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}

/**
 * heapify - heapifies a subtree
 * @array: array to sort
 * @size: size of array
 * @i: index of root node
 * @n: size of heap
 */

void heapify(int *array, size_t size, int i, int n)
{
	int largest, left, right, tmp;

	largest = i;
	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;
	if (right < n && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		tmp = array[i];
		array[i] = array[largest];
		array[largest] = tmp;
		print_array(array, size);
		heapify(array, size, largest, n);
	}
}
