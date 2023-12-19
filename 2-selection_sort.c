#include "sort.h"

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
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		if (min_idx != i)
		{
			swap_ints(array + i, array + min_idx);

			print_array(array, size);
		}
	}
}
