#include "sort.h"
#include <stdint.h>

/**
 * getMax - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * countingSort - Perform counting sort on an array of integers
 *                based on the significant digit at exp.
 * @array: An array of integers.
 * @size: The size of the array.
 * @exp: The current significant digit to consider.
 */
void countingSort(int *array, size_t size, int exp)
{
	int *output, count[10] = {0};
	size_t i;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i < SIZE_MAX; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);
	free(output);
}

/**
 * radix_sort - Sort an array of integers in ascending order
 *              using the LSD radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array each time the significant digit increases.
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = getMax(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
		countingSort(array, size, exp);
}
