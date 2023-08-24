#include "sort.h"

/**
 * swap_value - swap the values of two elements
 * @value1: pointer to an int
 * @value2: pointer to an int
 */

void swap_value(int *value1, int *value2)
{
	int temp;

	temp = *value1;
	*value1 = *value2;
	*value2 = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	int value = 0;
	size_t smallElement, largeElement;

	if (size < 2)
		return;

	for (smallElement = 0; smallElement < size; smallElement++)
	{
		value = 0;

		for (largeElement = 0; largeElement < size - 1; largeElement++)
		{
			if (array[largeElement] > array[largeElement + 1])
			{
				swap_value(array + largeElement, array + largeElement + 1);
				print_array(array, size);
				value = 1;
			}
		}

		if (!value)
			break;
	}
}
