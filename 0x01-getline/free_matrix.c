#include "laps.h"
/**
 * free_matrix - free array
 * @arr:	array
 * @n:		number of elements
 */
void free_matrix(int **arr, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		free(arr[i]);
	}
	free(arr);
}
