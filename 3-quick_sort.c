#include "sort.h"
#include <stddef.h>

/**
 * lomuto_partition - Lomuto partition scheme for quicksort.
 * @array: The array to be sorted.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: Number of elements in the array.
 * @Print: A function pointer to print the array
 * Return: The index of the pivot element after partitioning
 */
int lomuto_partition(int *array, int low, int high,
		size_t size, void (*Print)(const int *, size_t))
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			Print(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	Print(array, size);

	return (i + 1);
}

/**
 * quicksort - Recursive function to perform quicksort.
 * @array: The array to be sorted.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: Number of elements in the array.
 * @Print: A function pointer to print the array.
 */
void quicksort(int *array, int low, int high,
		size_t size, void (*Print)(const int *, size_t))
{
	if (low < high)
	{
		int partitionIndex = lomuto_partition(array, low, high, size, Print);

		quicksort(array, low, partitionIndex - 1, size, Print);
		quicksort(array, partitionIndex + 1, high, size, Print);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick sort algorithm with the Lomuto partition scheme.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size, print_array);
}
