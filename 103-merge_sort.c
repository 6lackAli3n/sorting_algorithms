#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays of array[].
 * @array: Pointer to the array to be sorted
 * @left: Pointer to the left subarray
 * @right: Pointer to the right subarray
 * @size_left: Size of the left subarray
 * @size_right: Size of the right subarray
 */
void merge(int *array, int *left, int *right,
		size_t size_left, size_t size_right)
{
	size_t i = 0, j = 0, k = 0;
	int *temp = malloc((size_left + size_right) * sizeof(int));

	printf("Merging...\n[left]: ");
	print_array(left, size_left);
	printf("[right]: ");
	print_array(right, size_right);

	while (i < size_left && j < size_right)
	{
		if (left[i] <= right[j])
		{
			temp[k++] = left[i++];
		} else
		{
			temp[k++] = right[j++];
		}
	}

	while (i < size_left)
	{
		temp[k++] = left[i++];
	}

	while (j < size_right)
	{
		temp[k++] = right[j++];
	}

	for (i = 0; i < size_left + size_right; i++)
	{
		array[i] = temp[i];
	}

	printf("[Done]: ");
	print_array(array, size_left + size_right);

	free(temp);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (size > 1)
	{
		size_t middle = size / 2;
		int *left = array;
		int *right = array + middle;
		size_t size_left = middle;
		size_t size_right = size - middle;

		merge_sort(left, size_left);
		merge_sort(right, size_right);
		merge(array, left, right, size_left, size_right);
	}
}

