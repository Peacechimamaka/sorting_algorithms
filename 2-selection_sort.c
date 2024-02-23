#include "sort.h"

/**
 *swap - the function swaps two integers
 *
 *@i: the first imteger parameter
 *@j: second integer parameter
 *
 * Return: nothing
 */
void swap(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

/**
 *selection_sort - sorts an element using the selection sort techniques
 *
 *@array: the array to be sorted
 *@size: size of the array
 *
 * Return: nothing
 */

void selection_sort(int *array, size_t size)
{
	int *least;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		least = array + i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *least)
				least = array + j;
			least = least;
		}
		if ((array + i) != least)
		{
			swap(array + i, least);
			print_array(array, size);
		}
	}
}
