#include "sort.h"

void swap(int* i, int* j)
{
        int temp;

        temp = *i;
        *i = *j;
        *j = temp;
}

void bubble_sort(int *array, size_t size)
{
        size_t i, j;

        for (i =0; i < size-1; i++)
        {

                for (j = 0; j < size - i - 1; j++)
                {

                        if(array[j] > array[j + 1])
                        {
                                 swap(&array[j], &array[j + 1]);

                                 print_array(array, size);
                                 
                        }
}
}
}
