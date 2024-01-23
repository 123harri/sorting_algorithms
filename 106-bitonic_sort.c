#include "sort.h"

/**
 * exchange_integers - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void exchange_integers(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * merge_bitonic_sequence - Sort a bitonic sequence inside an array of integers.
 * @arr: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @order: The direction to sort in.
 */
void merge_bitonic_sequence(int *arr, size_t size,
		size_t start, size_t seq, char order)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((order == 'U' && arr[i] > arr[i + jump]) ||
					(order == 'D' && arr[i] < arr[i + jump]))
				exchange_integers(arr + i, arr + i + jump);
		}
		merge_bitonic_sequence(arr, size, start, jump, order);
		merge_bitonic_sequence(arr, size, start + jump, jump, order);
	}
}

/**
 * build_bitonic_sequence - Convert an array of integers into a bitonic sequence.
 * @arr: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @order: The direction to sort the bitonic sequence block in.
 */
void build_bitonic_sequence(int *arr, size_t size,
		size_t start, size_t seq, char order)
{
	size_t cut = seq / 2;
	char *str = (order == 'U') ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(arr + start, seq);

		build_bitonic_sequence(arr, size, start, cut, 'U');
		build_bitonic_sequence(arr, size, start + cut, cut, 'D');
		merge_bitonic_sequence(arr, size, start, seq, order);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(arr + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @arr: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (i.e., size equal to powers of 2).
 */
void bitonic_sort(int *arr, size_t size)
{
	if (arr == NULL || size < 2)
		return;

	build_bitonic_sequence(arr, size, 0, size, 'U');
}
