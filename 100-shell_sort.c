#include "sort.h"

/**
 * shell_sort - a function that sorts an array of integers in ascending
 * order using a shell
 * sort algorithm, with spc sizes determined by a decreasing Knuth seqeuence
 * @array: array to be sorted
 * @size: array size
 **/

void shell_sort(int *array, size_t size)
{
	int a, b, spc, n, n_max, tmp;

	if (!array || size < 2)
		return;

	n = (int)size;
	for (spc = 1; spc < n; spc = (spc * 3) + 1)
	{
		n_max = spc;
	}
	for (spc = n_max; spc > 0; spc = (spc - 1) / 3)
	{
		for (a = spc; a < n; a++)
		{
			tmp = array[a];
			for (b = a; b >= spc && array[b - spc] > tmp; b -= spc)
			{
				array[b] = array[b - spc];
			}
			array[b] = tmp;
		}
		print_array(array, size);
	}
}
