#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t low, size_t k, int dir);
void bitonic_seque(int *array, size_t low, size_t k, int dir);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_merge - Merges bitonic sequence inside an array of integers
 *
 * @array: The array to be sorted
 * @low: The starting index of the first bitonic sequence
 * @k: The number of elements in each bitonic sequence
 * @dir: The direction of sorting, 1 for ascending, 0 for descending
 */
void bitonic_merge(int *array, size_t low, size_t k, int dir)
{
	size_t i, j, mid = k / 2;

	if (k > 1)
	{
		for (i = low; i < low + mid; i++)
		{
			j = i + mid;

			if ((dir == 1 && array[i] > array[j]) ||
					(dir == 0 && array[i] < array[j]))
				swap_ints(array + i, array + j);
		}
		bitonic_merge(array, low, mid, dir);
		bitonic_merge(array, low + mid, mid, dir);
	}
}


/**
 * bitonic_seque - Convert a subarray of integers into a bitonic sequence.
 * @array: An array of integers.
 * @low: The starting index of the subarray.
 * @k: The number of elements in the subarray.
 * @dir: The direction to sort the bitonic sequence in (1 for ascending, 0 for descending).
 */
void bitonic_seque(int *array, size_t low, size_t k, int dir)
{
	size_t cut = k / 2;
	char *str = (dir == 1) ? "UP" : "DOWN";

	if (k > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", k, low + k, str);
		print_array(array + low, k);

		bitonic_seque(array, low, cut, 1);
		bitonic_seque(array, low + cut, cut, 0);
		bitonic_merge(array, low, k, dir);

		printf("Result [%lu/%lu] (%s):\n", k, low + k, str);
		print_array(array + low, k);
	}
}


/**
 * bitonic_sort - Sorts an array of integers in ascending order
 *		 using the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seque(array, 0, size, 1);
}
