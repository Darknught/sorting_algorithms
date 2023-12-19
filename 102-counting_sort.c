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
	int k, l, *counting;
	size_t x, y, max = 0;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size; x++)
	{
		if ((size_t)array[x] > max)
			max = (size_t)array[x];
	}
	max++;

	counting = malloc(max * sizeof(int));
	if (counting == NULL)
		return;

	for (x = 0; x < max; x++)
		counting[x] = 0;

	for (x = 0; x < size; x++)
		counting[array[x]]++;

	
	for (k = 0; k < (int)max; k++)
	{
		for (l = 0; l < counting[k]; l++)
		{
			printf("%d", (int)k);
			if (k < (int)max - 1 || (int)l < counting[k] - 1)
				printf(", ");
		}
	}
	printf("\n");

	y = 0;
	for (x = 0; x < max; x++)
	{
		while (counting[x] > 0)
		{
			array[y] = x;
			y++;
			counting[x]--;
		}
	}

	free(counting);
}
