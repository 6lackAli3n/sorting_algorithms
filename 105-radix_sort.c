#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort_radix - Perform counting sort based on a specific digit
 * @array: Array to be sorted
 * @size: Size of the array
 * @exp: Exponent representing the current digit place value
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (output == NULL)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size; i > 0; i--)
	{
		output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using LSD Radix sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = array[0];
	size_t i;
	int exp;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	for (exp = 1; max / exp > 0; exp *= 10)
		counting_sort_radix(array, size, exp);
}
