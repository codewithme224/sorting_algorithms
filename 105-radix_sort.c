#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 */

void radix_sort(int *array, size_t size)
{
	int i, max, exp;

	if (!array || size < 2)
		return;
	max = array[0];

	for (i = 1; i < (int)size; i++)
		if (array[i] > max)
			max = array[i];
	for (exp = 1; max / exp > 0; exp *= 10)
		count_sort(array, size, exp);
}

/**
 * count_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 * @exp: exponent
 */

void count_sort(int *array, size_t size, int exp)
{
	int i, *output, count[10] = {0};

	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
	print_array(array, size);
	free(output);
}
