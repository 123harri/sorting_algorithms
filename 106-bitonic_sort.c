#include "sort.h"

/**
 * swap_elements - Swap two elements in an array.
 * @element1: The first element to swap.
 * @element2: The second element to swap.
 */
void swap_elements(int *element1, int *element2)
{
	int temporary = *element1;
	*element1 = *element2;
	*element2 = temporary;
}

/**
 * bitonic_merge - Perform the merging step in the Bitonic Sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 * @start: The starting index of the sequence in the array to sort.
 * @sequence_size: The size of the sequence to sort.
 * @direction: The direction to sort
 */
void bitonic_merge(int *array, size_t size, size_t start,
		size_t sequence_size, char direction)
{
	size_t i, jump = sequence_size / 2;

	if (sequence_size > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((direction == 'A' && array[i] > array[i + jump]) ||
			    (direction == 'D' && array[i] < array[i + jump]))
				swap_elements(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, direction);
		bitonic_merge(array, size, start + jump, jump, direction);
	}
}

/**
 * bitonic_sequence - Convert an array of integers into a bitonic sequence.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @sequence_size: The size of a block of the building bitonic sequence.
 * @direction: The direction to sort the bitonic sequence block
 */
void bitonic_sequence(int *array, size_t size, size_t start,
		size_t sequence_size, char direction)
{
	size_t cut = sequence_size / 2;
	char *sort_direction = (direction == 'A') ? "UP" : "DOWN";

	if (sequence_size > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n",
				sequence_size, size, sort_direction);
		print_array(array + start, sequence_size);

		bitonic_sequence(array, size, start, cut, 'A');
		bitonic_sequence(array, size, start + cut, cut, 'D');
		bitonic_merge(array, size, start, sequence_size, direction);

		printf("Result [%lu/%lu] (%s):\n",
				sequence_size, size, sort_direction);
		print_array(array + start, sequence_size);
	}
}

/**
 * bitonic_sort - Sort an array of integers using the Bitonic Sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (i.e., size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sequence(array, size, 0, size, 'D');
}
