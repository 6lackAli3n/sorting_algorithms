#include "sort.h"
#include <stdio.h>

/**
 * bitonic_merge - merges two subarrays of bitonic array
 * @array: array to sort
 * @low: starting index of first subarray
 * @count: number of elements to be sorted
 * @dir: sorting direction
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;
		size_t i;

		for (i = low; i < low + k; i++)
		{
			if ((array[i] > array[i + k]) == dir)
			{
				int temp = array[i];
				array[i] = array[i + k];
				array[i + k] = temp;
			}
		}
		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - recursively sorts a bitonic sequence
 * @array: array to sort
 * @low: starting index of the sequence
 * @count: number of elements in the sequence
 * @dir: sorting direction
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;
		bitonic_sort_recursive(array, low, k, 1);
		bitonic_sort_recursive(array, low + k, k, 0);
		bitonic_merge(array, low, count, dir);
	}
}

/**
 * bitonic_sort - sorts an array of integers in ascending order using bitonic sort
 * @array: array to sort
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	bitonic_sort_recursive(array, 0, size, 1);
}

