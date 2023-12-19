#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, int low, int high, size_t size);
void hoare_sort(int *array, int low, int high, size_t size);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 *
 * Authors: Lawrence Adams & Francesca Lynn Asiedu Asare
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Partition an array of integers using the Hoare scheme.
 * @array: An array of integers.
 * @low: The starting index of the subarray to be partitioned.
 * @high: The ending index of the subarray to be partitioned.
 * @size: The size of the array.
 * Return: The final partition index.
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot, above, below;

	pivot = array[high];
	for (above = low - 1, below = high + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}


/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The starting index of the array partition to order.
 * @high: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, int low, int high, size_t size)
{
	int part;

	if (high - low > 0)
	{
		part = hoare_partition(array, size, low, high);
		hoare_sort(array, size, low, part - 1);
		hoare_sort(array, size, part, high);
	}
}


/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using the Quick sort algorithm with Hoare partition scheme
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
