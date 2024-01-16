#include "search_algos.h"
#include <math.h>

/**
 * min - Returns the minimum of two numbers
 * @a: First number
 * @b: Second number
 * Return: The smaller of a and b
 */
size_t min(size_t a, size_t b)
{
	return ((a < b) ? a : b);
}

/**
 * jump_search - Searches for a value in a sorted array of integers
 * using the Jump search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 * Return: The first index value is located or -1 if not found or array's NULL
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step = sqrt(size);
	size_t prev = 0;
	size_t next = 0;

	if (!array)
		return (-1);

	while (next < size && array[next] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", next, array[next]);
		prev = next;
		next += step;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
			prev, min(next, size - 1));

	while (prev < min(next, size))
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		if (array[prev] == value)
			return (prev);
		prev++;
	}

	return (-1);
}
