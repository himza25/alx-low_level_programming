#include "search_algos.h"
#include <math.h>

/**
 * jump_search - Implements Jump Search algorithm for sorted arrays
 * @array: Pointer to the first element of the array
 * @size: The number of elements in the array
 * @value: The value to search for
 * Return: The index value is found, or -1 if not present or if array's NULL
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step = (size_t)sqrt(size), idx = 0;
	size_t prev;

	if (!array)
		return (-1);

	while (idx < size && array[idx] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", idx, array[idx]);
		idx += step;
	}

	prev = (idx < step) ? 0 : idx - step;
	printf("Value found between indexes [%ld] and [%ld]\n", prev, idx);

	while (prev < size && array[prev] <= value)
	{
		printf("Value checked array[%ld] = [%d]\n", prev, array[prev]);
		if (array[prev] == value)
			return (prev);
		prev++;
	}

	return (-1);
}
