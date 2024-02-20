#include "sort.h"

/**
 *quick_sort - Sorts an array of integers using Quick sort algorithm
 *@array: The array to be sorted
 *@size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	void lomuto_partition(int *array, int low, int high, size_t size);

	if (size < 2)
		return;

	lomuto_partition(array, 0, size - 1, size);
}

/**
 *lomuto_partition - Lomuto partition scheme for Quick sort
 *@array: The array to be partitioned
 *@low: Starting index of the partition
 *@high: Ending index of the partition
 *@size: Size of the array
 */
void lomuto_partition(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = array[high];
		int i = low - 1;
		int j, temp;

		for (j = low; j <= high - 1; j++)
		{
			if (array[j] < pivot)
			{
				i++;
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}

		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);

		int p = i + 1;

		lomuto_partition(array, low, p - 1, size);
		lomuto_partition(array, p + 1, high, size);
	}
}
