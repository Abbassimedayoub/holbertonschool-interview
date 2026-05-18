#include "search_algos.h"

/**
 * find_index - Finds the first occurrence of a value in an array
 * @an_array: Sorted array of integers
 * @start: Index indicating the start of the sub-array
 * @end: Index indicating the end of the sub-array
 * @val: Value to search for
 *
 * Return: Index where value is located, or -1 otherwise
 */
int find_index(int *an_array, size_t start, size_t end, int val)
{
	size_t i, index, pos, len;

	if (start == end)
		return (-1);

	printf("Searching in array: ");
	for (i = start; i < end; i++)
	{
		printf("%d", an_array[i]);

		if (i < end - 1)
			printf(", ");
	}
	printf("\n");

	pos = index = (start + end - 1) / 2;
	len = end - start;

	if (len > 0 && an_array[index] == val &&
		(index == 0 || an_array[index - 1] < val))
		pos = index;

	else if (an_array[index] == val &&
		 index > 0 && an_array[index - 1] == val)
		pos = find_index(an_array, start, index + 1, val);

	else if (an_array[index] < val)
		pos = find_index(an_array, index + 1, end, val);

	else if (an_array[index] > val)
		pos = find_index(an_array, start, index + 1, val);

	else
		pos = -1;

	return (pos);
}

/**
 * advanced_binary - Finds a value in a sorted array
 * @array: Array of integers
 * @size: Size of the array
 * @value: Value to search for
 *
 * Return: Index position if found, or -1 otherwise
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size < 1)
		return (-1);

	return (find_index(array, 0, size, value));
}