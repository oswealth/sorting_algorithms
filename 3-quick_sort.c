#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int low, int high);
void lomuto_sort(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array
 *
 * @a: The first integer to swap
 * @b: The second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The starting index of the subset to order.
 * @high: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int *pivot, above, below;

	pivot = array + high;
	for (above = below = low; below < high; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}


/**
 * lomuto_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm with the Lomuto partition scheme
 *
 * @array: The array to be sorted
 * @low: The lowest index of the partition to sort
 * @high: The highest index of the partition to sort
 * @size: The size of the array
 */
void lomuto_sort(int *array, int low, int high, size_t size)
{
	int pivt;

	if (low < high)
	{
		pivt = lomuto_partition(array, low, high, size);
		lomuto_sort(array, low, pivt  - 1, size);
		lomuto_sort(array, pivt + 1, high, size);
	}
}


/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

 	/* Call the helper function to sort the array recursively */
	lomuto_sort(array, 0, -1, size);
}
