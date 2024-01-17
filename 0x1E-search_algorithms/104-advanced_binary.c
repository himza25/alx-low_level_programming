#include "search_algos.h"

int recursive_binary_search(int *array, size_t low, size_t high, int value);

/**
 * print_array - Prints an array of integers.
 * @array: The array to be printed.
 * @low: The starting index of the subarray to be printed.
 * @high: The ending index of the subarray to be printed.
 */
void print_array(int *array, size_t low, size_t high)
{
	size_t i;

	printf("Searching in array: ");
	for (i = low; i < high; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
}

/**
 * recursive_binary_search - Recursively searches for a value in a sorted array
 * @array: A pointer to the first element of the array to search in.
 * @low: The lower bound of the subarray to search in.
 * @high: The upper bound of the subarray to search in.
 * @value: The value to search for.
 * Return: The first index where value is located, or -1 if value not present.
 */
int recursive_binary_search(int *array, size_t low, size_t high, int value)
{
	if (high >= low)
	{
		size_t mid = low + (high - low) / 2;

		/* Print the current subarray being searched */
		print_array(array, low, high);

		/* Check if the middle element is the first occurrence */
		if ((mid == low || value > array[mid - 1]) && array[mid] == value)
			return (mid);

		/* If the value is smaller than mid or not first occurrence */
		if (value <= array[mid])
			return (recursive_binary_search(array, low, mid, value));

		/* Else search in the right subarray */
		return (recursive_binary_search(array, mid + 1, high, value));
	}

	/* Element is not present in the array */
	return (-1);
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 * Return: The first index where value is located, or -1 if not present.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (recursive_binary_search(array, 0, size - 1, value));
}
