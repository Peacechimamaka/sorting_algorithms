#include "sort.h"

/**
 * swap - This function swaps the values of two integer variables.
 *
 * @i: A pointer to the first integer variable.
 * @j: A pointer to the second integer variable.
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
 * bubble_sort - Sorts an array of integers in ascending order using the
 * bubble sort algorithm.
 *
 * @array: A pointer to the array of integers to be sorted.
 * @size: The number of elements in the array.
 *
 * Returns: This function does not return any value directly.
 * Instead, it sorts the input array in place.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (size <= 2)
		return;

	if (array != NULL)
	{
		for (i = 0; i < size - 1; i++)
		{

			for (j = 0; j < size - i - 1; j++)
			{

				if (array[j] > array[j + 1])
				{
					swap(&array[j], &array[j + 1]);
					print_array(array, size);

				}
			}
		}
	}
}
