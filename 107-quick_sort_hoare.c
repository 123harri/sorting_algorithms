#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @first: The first integer to swap.
 * @second: The second integer to swap.
 */
void swap_ints(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * hoare_partition - Perform Hoare partitioning on a subset of an array.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset.
 * @right: The ending index of the subset.
 *
 * Return: The final index of the partition.
 *
 * Description: Uses the last element of the subset as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
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
 * hoare_sort - Recursively implement the Hoare quicksort algorithm.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @start: The starting index of the array partition.
 * @end: The ending index of the array partition.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int start, int end)
{
	int partition_index;

	if (end - start > 0)
	{
		partition_index = hoare_partition(array, size, start, end);
		hoare_sort(array, size, start, partition_index - 1);
		hoare_sort(array, size, partition_index, end);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending order
 *                    using the Hoare partition scheme.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
