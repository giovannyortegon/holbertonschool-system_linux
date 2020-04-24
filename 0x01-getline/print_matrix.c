#include "laps.h"
/**
 * print_matrix - Print all array
 * @arr:	array
 * @n:		number of elements
 */
void print_matrix(int **arr, size_t n)
{
	size_t i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}
