#include "sort.h"

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b) {
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
 *
 * Return: The index of the pivot element.
 */
int partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = (low - 1), j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}


/**
 * quick_sort - Sorts an integer array
 * in ascending order using Quick Sort.
 * @array: Pointer to the integer array to be sorted.
 * @low: Starting index of the array to be sorted.
 * @high: Ending index of the array to be sorted.
 */
void quick_sort(int *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);

        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}
