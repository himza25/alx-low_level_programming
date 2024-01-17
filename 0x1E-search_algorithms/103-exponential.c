#include "search_algos.h"

/**
 * binary_search_print - Searches for a value in a sorted array of integers.
 * @array: A pointer to the first element of the array to search in.
 * @left: The starting index of the subarray to search in.
 * @right: The ending index of the subarray to search in.
 * @value: The value to search for.
 *
 * Return: The first index where value is located.
 */
int binary_search_print(int *array, size_t left, size_t right, int value)
{
	size_t i;

	while (left <= right)
	{
		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		size_t mid = left + (right - left) / 2;

		if (array[mid] == value)
			return (mid);
		if (array[mid] > value)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return (-1);
}

/**
 * exponential_search - Searches a value using the Exponential search.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in array.
 * @value: The value to search for.
 *
 * Return: The first index where value is located.
 */
int exponential_search(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	size_t bound = 1;

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	size_t left = bound / 2;
	size_t right = (bound < size) ? bound : size - 1;

	printf("Value found between indexes [%lu] and [%lu]\n", left, right);

	return (binary_search_print(array, left, right, value));
}
