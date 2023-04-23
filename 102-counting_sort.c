#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * size_t - the number of elements in an array
 * @array: array to sort
 * @size: size of array
 */

void counting_sort(int *array, size_t size)
{
	int *count, *output, max_value, i;

	if (!array || size < 2)
		return;
	max_value = array[0];
	for (i = 1; i < (int)size; i++)
		if (array[i] > max_value)
			max_value = array[i];
	count = malloc(sizeof(int) * (max_value + 1));
	if (!count)
		return;
	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}

	for (i = 0; i <= max_value; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	for (i = 1; i <= max_value; i++)
		count[i] += count[i - 1];
	print_array(count, max_value + 1);
	for (i = 0; i < (int)size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
