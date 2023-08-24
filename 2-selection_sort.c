#include "sort.h"

/**
 * swap_value - swap the int values of two addresses
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
 * selection_sort - sorts an array of integers
 * @array: array of integers
 * @size: length of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t smallElement, j, min_index;

	for (smallElement = 0; smallElement < size; smallElement++)
	{
		min_index = smallElement;
		for (j = smallElement + 1; j < size; j++)
		{
			if (array[min_index] > array[j])
				min_index = j;
		}

		if (min_index != smallElement)
		{
			swap_value(array + smallElement, array + min_index);
			print_array(array, size);
		}
	}
}
