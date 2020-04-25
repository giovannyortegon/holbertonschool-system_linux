#include "laps.h"
/**
 * print_matrix - Print all array
 * @arr:	array
 * @n:		number of elements
 */
void print_matrix(int **arr, size_t n)
{
	size_t i, j;

	printf("Race state:\n");
	for (i = 0; i < n; i++)
	{
		printf("Car %d [%d laps]\n",
				arr[i][0],
				arr[i][1]);
	}
}
