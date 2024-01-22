#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * max_heapify - Heapify a subtree rooted at given index.
 * @array: The array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @heap_size: The size of the heap to consider.
 * @root: The root index of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t heap_size, size_t root)
{
	size_t left, right, largest;

	left = 2 * root + 1;
	right = 2 * root + 2;
	largest = root;

	if (left < heap_size && array[left] > array[largest])
		largest = left;
	if (right < heap_size && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap_ints(array + root, array + largest);
		print_array(array, size);
		max_heapify(array, size, heap_size, largest);
	}
}

/**
 * heap_sort_recursive - Recursive function to
 * implement the heap sort algorithm.
 * @array: The array of integers.
 * @size: The size of the array.
 * @end: The current end index.
 */
void heap_sort_recursive(int *array, size_t size, size_t end)
{
	if (end == 0)
		return;

	swap_ints(array, array + end);
	print_array(array, size);
	max_heapify(array, size, end, 0);
	heap_sort_recursive(array, size, end - 1);
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	heap_sort_recursive(array, size, size - 1);
}
