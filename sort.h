#ifndef SORT_H
#define SORT_H
/*Includes*/
#include <stdio.h>
#include <stdlib.h>

/*Structs*/
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*Prototypes*/

void print_list(const listint_t *list);

void print_array(const int *array, size_t size);

void bubble_sort(int *array, size_t size);

void insertion_sort_list(listint_t **list);

void selection_sort(int *array, size_t size);

void quick_sort(int *array, size_t size);

void cocktail_sort_list(listint_t **list);

void swap_nodes(listint_t *node1, listint_t *node2, listint_t **list);

void quick_sort_helper(int *array, int low, int high, size_t size);

int partition(int *array, int low, int high, size_t size);

void shell_sort(int *array, size_t size);

void quick_sort_hoare(int *array, size_t size);

void bitonic_sort(int *array, size_t size);
void swap_array(int *array, size_t index, size_t j, size_t dir);
void merge_array(int *array, size_t low, size_t size, size_t dir);
void sort_array(int *array, size_t low, size_t size, size_t dir, size_t length);


void radix_sort(int *array, size_t size);

void count_sort(int *array, size_t size, int exp);

void heap_sort(int *array, size_t size);

void heapify(int *arr, size_t initialSize, size_t currentSize, size_t index);

void merge_sort(int *array, size_t size);

void merge(int *array, int *lo, int *hi, size_t size);


void counting_sort(int *array, size_t size);

#endif
