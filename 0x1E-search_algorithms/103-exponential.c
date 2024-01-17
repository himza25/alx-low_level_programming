#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * binary_search_print - searches using binary search algorithm and prints
 * @array: pointer to the first element of the array
 * @left: left index of subarray
 * @right: right index of subarray
 * @value: value to search for
 *
 * Return: index where value is located or -1
 */
int binary_search_print(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	while (right >= left)
	{
		printf("Searching in array: ");
		for (size_t i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[right]);

		mid = left + (right - left) / 2;
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
 * exponential_search - searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index where value is located, or -1 if value is not present
 * or array is NULL
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;

	if (!array)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	bound = (bound < size) ? bound : size - 1;
	printf("Value found between indexes [%lu] and [%lu]\n", bound / 2, bound);
	return (binary_search_print(array, bound / 2, bound, value));
}
