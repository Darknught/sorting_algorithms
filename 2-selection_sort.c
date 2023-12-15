#include "sort.h"

/**
 * swap - function to swap integers
 * @x: first integer
 * @y: second integer
 *
 */
void swap(int *x, int *y)
{
	int tmp = *x;

	*x = *y;
	*y = tmp;
}

/**
 * selection_sort - Sorts an integer array in
 * ascending order using the selection sort algorithm.
 * @array: Pointer to the integer array to be sorted.
 * @size: Size of the array.
 */
void selection_sort(int *array, size_t size)
{
size_t i, j, min_index;

for (i = 0; i < size - 1; i++)
{
min_index = i;
for (j = i + 1; j < size; j++)
{
if (array[j] < array[min_index])
{
min_index = j;
}
}
if (min_index != i)
{
swap(&array[i], &array[min_index]);
print_array(array, size);
}
}
}
