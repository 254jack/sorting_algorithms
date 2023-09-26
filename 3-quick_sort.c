#include "sort.h"

/**
 * partition - a function that scans a partition of
 * an array of integers
 * @array: array
 * @low: index that starts partition 
 * @high: index that ends partition
 * @size: array size
 * Return: 0
 */
int partition(int *array, int low, int high, size_t size)
{
	int a, b, pivot, tmp;

	pivot = array[high];
	a = low;
	for (b = low; b < high; b++)
	{
		if (array[b] < pivot)
		{
			tmp = array[a];
			array[a] = array[b];
			array[b] = tmp;
			if (array[a] != array[b])
				print_array(array, size);
			a++;
		}
	}
	tmp = array[a];
	array[a] = array[high];
	array[high] = tmp;
	if (array[a] != array[high])
		print_array(array, size);
	return (a);
}

/**
 * quicksort - a function that recursively sorts array of integers by
 * separating into two partitions, using Lomuto quick sort
 * @array: array
 * @low: index that begins a partition
 * @high: index that ends a partition
 * @size: amount of elements in array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int t;

	if (low < high)
	{
		t = partition(array, low, high, size);
		quicksort(array, low, t - 1, size);
		quicksort(array, t + 1, high, size);
	}
}

/**
 * quick_sort - a function that sorts an array of integers in
 * ascending order using a quick sort algorithm, with Lomuto
 * partition scheme
 * @array: array to be sorted
 * @size: size
 **/

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, (int)size - 1, size);
}
