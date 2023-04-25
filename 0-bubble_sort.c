#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array to sort
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int index = 0, j = 0;

	if (size <= 1)
		return;

	for (index = 0; index < (size - 1); index++)
		for (j = 1; j < size; j++)
			if (array[j - 1] > array[j])
			{
				swap_integers(&array[j - 1], &array[j]);
				print_array(array, size);
			}

}

/**
 * swap_integers - swap two pointers to integer
 *
 * @a: first int pointer
 * @b: second int pointer
 */
void swap_integers(int *a, int *b)
{
	int swap_integers;

	swap_integers = *a;
	*a = *b;
	*b = swap_integers;
}
