#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers.
 *
 * @i: Pointer to the first integer.
 * @j: Pointer to the second integer.
 *
 * Return: Nothing
*/
void swap(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * partition - Partitions the array around a pivot element for quicksort.
 *
 * @array: The array to partition.
 * @low: The lowest index of the array or subarray.
 * @high: The highest index of the array or subarray.
 * Return: The index of the pivot element after partitioning.
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i, j;

	for (j = low, i = low - 1; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, high + 1);
		}
	}

	swap(&array[i + 1], &array[high]);
	print_array(array, high + 1);

	return (i + 1);
}

/**
 * lomuto_sort - Sorts an array of integers from ascending to descending order.
 *
 * @array: The array to be sorted.
 * @low: The lowest index of the array or subarray.
 * @high: The highest index of the array or subarray.
 *
 * Return: Nothing
 */
void lomuto_sort(int *array, int low, int high)
{
	int pivot_index;

	if (low >= high)
		return;

	pivot_index = partition(array, low, high);

	lomuto_sort(array, low, pivot_index - 1);
	lomuto_sort(array, pivot_index + 1, high);

}

/**
 * quick_sort - Initiates the quicksort algorithm on an array.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, 0, size - 1);
}
