#include "sort.h"

/**
 * compare_swap_down - compares and swaps elements in the down direction
 * @init_array: the original array being sorted
 * @sub_array: array to sort
 * @init_size: the size of the original array
 * @size: size of array
 * @flag: flag to signal the end of the recursion
 */
void compare_swap_down(int *init_array, int *sub_array,
		size_t init_size, size_t size, int *flag)
{
	int temp;
	size_t i;
	(void)init_array;

	if (flag[0] == 0)
	{
		for (i = 0; i < size / 2; i++)
		{
			if (sub_array[0] < sub_array[size - 1])
			{
				temp = sub_array[0];
				sub_array[0] = sub_array[size - 1];
				sub_array[size - 1] = temp;
				printf("Result [%lu/%lu] (DOWN):\n", size, init_size);
				print_array(sub_array, size);
			}
		}
	}
}

/**
 * compare_swap_up - compares and swaps elements in the up direction
 * @init_array: the original array being sorted
 * @sub_array: array to sort
 * @init_size: the size of the original array
 * @size: size of array
 * @flag: flag to signal the end of the recursion
 */

void compare_swap_up(int *init_array, int *sub_array,
		size_t init_size, size_t size, int *flag)
{
	int temp;
	size_t i;
	(void)init_array;

	if (flag[0] == 0)
	{
		for (i = 0; i < size / 2; i++)
		{
			if (sub_array[0] > sub_array[size - 1])
			{
				temp = sub_array[0];
				sub_array[0] = sub_array[size - 1];
				sub_array[size - 1] = temp;
				printf("Result [%lu/%lu] (UP):\n", size, init_size);
				print_array(sub_array, size);
			}
		}
	}
}

/**
 * bitonic_deep_down - recursively calls the bitonic sort in the down direction
 * @init_array: the original array being sorted
 * @sub_array: array to sort
 * @init_size: the size of the original array
 * @size: size of array
 * @flag: flag to signal the end of the recursion
 */

void bitonic_deep_down(int *init_array, int *sub_array,
		size_t init_size, size_t size, int *flag)
{
	(void)sub_array;

	if (size < 2)
	{
		flag[0] = 0;
		return;
	}
	printf("Merging [%lu/%lu] (DOWN):\n", size, init_size);
	print_array(init_array, size);
	bitonic_deep_up(init_array, sub_array, init_size, size / 2, flag);
	compare_swap_up(init_array, sub_array, init_size, size, flag);
	bitonic_deep_down(init_array, sub_array +
			(size / 2), init_size, size / 2, flag);
	compare_swap_down(init_array, sub_array, init_size, size, flag);
}

/**
 * bitonic_deep_up - recursively calls the bitonic sort in the up direction
 * @init_array: the original array being sorted
 * @sub_array: array to sort
 * @init_size: the size of the original array
 * @size: size of array
 * @flag: flag to signal the end of the recursion
 */

void bitonic_deep_up(int *init_array, int *sub_array,
		size_t init_size, size_t size, int *flag)
{
	(void)sub_array;

	if (size < 2)
	{
		flag[0] = 0;
		return;
	}
	printf("Merging [%lu/%lu] (UP):\n", size, init_size);
	print_array(init_array, size);
	bitonic_deep_up(init_array, sub_array, init_size, size / 2, flag);
	compare_swap_up(init_array, sub_array, init_size, size, flag);
	bitonic_deep_down(init_array, sub_array +
			(size / 2), init_size, size / 2, flag);
	compare_swap_down(init_array, sub_array, init_size, size, flag);
}

/**
 * bitonic_sort - sorts an array of integers in
 * ascending order using the Bitonic sort algorithm
 * @array: array to sort
 * @size: size of array
 */

void bitonic_sort(int *array, size_t size)
{
	size_t init_size = size;
	int *init_array = array;
	int *flag;
	int aux = {0};

	flag = &aux;
	if (array)
	{
		bitonic_deep_up(init_array, init_array, init_size, size, flag);
	}
}
