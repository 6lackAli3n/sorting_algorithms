#include "sort.h"
#include <stdio.h>
void swap(int *a, int *b);
/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - Repair the heap whose root element
 *             is at index 'start', assuming the
 *             heaps rooted at its children are valid.
 * @array: The array to sort
 * @start: The root of the heap to repair
 * @end: The end of the array
 * @size: The size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		if (child + 1 <= end && array[child] < array[child + 1])
			child++;
		if (array[root] < array[child])
		{
			swap(&array[root], &array[child]);
			print_array(array, size);
			root = child;
		}
		else
			return;
	}
}

/**
 * heapify - Perform heap sort
 * @array: The array to sort
 * @size: The size of the array
 */
void heapify(int *array, size_t size)
{
	size_t start;

	for (start = size / 2 - 1; (int)start >= 0; start--)
		sift_down(array, start, size - 1, size);
}

/**
 * heap_sort - Sort an array of integers in ascending order
 *             using the heap sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (!array || size < 2)
		return;

	heapify(array, size);

	for (end = size - 1; end > 0; end--)
	{
		swap(&array[end], &array[0]);
		print_array(array, size);
		sift_down(array, 0, end - 1, size);
	}
}

