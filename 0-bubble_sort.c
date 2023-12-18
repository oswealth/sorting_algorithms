#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using the
 * Bubble sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n, new_n;
	int swap;

	if (array == NULL || size < 2)
		return;

	n = size;
	while (n != 0)
	{
		new_n = 0;
		for (i = 1; i < n; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap = array[i - 1];
				array[i - 1] = array[i];
				array[i] = swap;
				new_n = i;
				print_array(array, size);
			}
		}
		n = new_n;
	}
}
