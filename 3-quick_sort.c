#include "sort.h"

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
 * partition - Partitions an array for the
 * Quick Sort algorithm.
 * @array: Pointer to the array to be partitioned.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: size
 * Return: The index of the pivot element.
 */
int partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = (low - 1), j;

for (j = low; j <= high - 1; j++)
{
if (array[j] < pivot)
{
i++;
swap(&array[i], &array[j]);
print_array(array, size);
}
}
swap(&array[i + 1], &array[high]);
/*print_array(array, size);*/
return (i + 1);
}

/**
 * quick_sort_helper - quick sort helper function
 * @array: array of items
 * @low: Starting index of the array to be sorted.
 * @high: Ending index of the array to be sorted.
 * @size: size
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
int pi;

if (low < high)
{
pi = partition(array, low, high, size);
quick_sort_helper(array, low, pi - 1, size);
quick_sort_helper(array, pi + 1, high, size);
}
}

/**
 * quick_sort - Sorts an integer array
 * in ascending order using Quick Sort.
 * @array: Pointer to the integer array to be sorted.
 * @size: size
 */
void quick_sort(int *array, size_t size)
{
quick_sort_helper(array, 0, size - 1, size);
}
