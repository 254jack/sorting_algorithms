#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers
 * using a selction sort algorithm
 * @array: array
 * @size: size
 */
void selection_sort(int *array, size_t size)
{
	int a, b, min_j, tmp, n = (int)size;

	if (!array || size < 2)
		return;

	for (a = 0; a < n - 1; a++)
	{
		min_j = a;
		for (b = a + 1; b < n; b++)
		{
			if (array[b] < array[min_j])
			{
				min_j = b;
			}
		}
		if (min_j != a)
		{
			tmp = array[a];
			array[a] = array[min_j];
			array[min_j] = tmp;
			print_array(array, size);
		}
	}
}
