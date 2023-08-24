#include "sort.h"

/**
 * swap_value - swap the values of two addresses
 * @node1: pointer to an int
 * @node2: pointer to an int
 */
void swap_value(int *node1, int *node2)
{
	int temp;

	temp = *node1;
	*node1 = *node2;
	*node2 = temp;
}

/**
 * divide_conquer - find and return the the index of the pivot
 * which is the middle index for dividing array
 * @array: half of array of integers
 * @size: length of the array
 * @left_i: left-most of half
 * @right_i: right-most of half
 * Return: size_t
 */
size_t divide_conquer(
		int *array, size_t size,
		long int left_i, long int right_i)
{
	long int i, j;
	int pivot = array[right_i];

	i = left_i - 1;
	for (j = left_i; j <= right_i; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i == j)
				continue;
			swap_value(array + j, array + i);
			print_array(array, size);
		}
	}

	return (i);
}

/**
 * sort - sort elements on the left and right of partition
 * @array: array of integers
 * @size: length of the array
 * @left_i: left-most boundary of array
 * @right_i: right-most boundary of array
 */
void sort(
		int *array, size_t size,
		long int left_i, long int right_i
	 )
{
	long int d;

	if (left_i >= right_i || left_i < 0)
		return;

	d = divide_conquer(array, size, left_i, right_i);

	sort(array, size, left_i, d - 1);
	sort(array, size, d + 1, right_i);
}

/**
 * quick_sort - using quick sort algorithm to
 * sort an array of integers with lomuto partiioning
 * @array: array of integers
 * @size: length of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	sort(array, size, 0, (long int) (size - 1));
}
