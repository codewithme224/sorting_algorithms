#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 */

void heap_sort(int *array, size_t size)
{
	size_t index, initialSize = size;
	int temp;

	if (!array)
		return;

	for (index = 0; index < size / 2 ; index++)
	{
		heapify(array, initialSize, size, size / 2 - 1 - index);
	}
	for (index = 0; index < initialSize - 1; index++)
	{
		temp = array[0];
		array[0] = array[size - 1 - index];
		array[size - 1 - index] = temp;
		print_array(array, initialSize);
		heapify(array, initialSize, size - index - 1, 0);
	}
}

/**
 * heapify - heapifies a subtree
 * @arr: array to sort
 * @currentSize: size of array
 * @initialSize: original size of the array
 * @index: index of root node
 */

void heapify(int *arr, size_t initialSize, size_t currentSize, size_t index)
{
	int current, left, right;
	size_t leftIndex, rightIndex;

	leftIndex = index * 2 + 1;
	rightIndex = leftIndex + 1;
	left = arr[leftIndex];
	right = arr[rightIndex];
	current = arr[index];

	if (((leftIndex < currentSize) &&
			(rightIndex < currentSize) &&
			(left >= right && left > current)) ||
			((leftIndex == currentSize - 1) &&
			left > current))
	{
		arr[index] = left;
		arr[leftIndex] = current;
		print_array(arr, initialSize);
	}
	else if (leftIndex < currentSize && rightIndex < currentSize &&
			(right > left && right > current))
	{
		arr[index] = right;
		arr[rightIndex] = current;
		print_array(arr, initialSize);
	}
	if (leftIndex < currentSize - 1)
		heapify(arr, initialSize, currentSize, leftIndex);
	if (rightIndex < currentSize - 1)
		heapify(arr, initialSize, currentSize, rightIndex);
}
