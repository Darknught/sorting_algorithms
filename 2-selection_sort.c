#include "sort.h"

void selection_sort(int *array, size_t size)
{
int temp;
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
temp = array[i];
array[i] = array[min_index];
array[min_index] = temp;
}
}
}
