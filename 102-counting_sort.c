#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using
 * couting sort
 * @array: The array to be sorted
 * @size: The size of the array
 *
 */
void counting_sort(int *array, size_t size)
{
	int *counting, max, i;
	size_t x, j;

	if (array == NULL || size < 2)
		return;

	max = array[0];

	for (x = 1; x < size; x++)
	{
		if (array[x] > max)
			max = array[x];
	}

	counting = malloc((max + 1) * sizeof(int));
	if (counting == NULL)
		return;

	for (i = 0; i <= max; i++)
		counting[i] = 0;

	for (x = 0; x < size; x++)
		counting[array[x]]++;

	print_array(counting, max + 1);

	j = 0;
	for (i = 0; i <= max; i++)
	{
		while (counting[i] > 0)
		{
			array[j] = i;
			j++;
			counting[i]--;
		}
	}
	free(counting);
}
