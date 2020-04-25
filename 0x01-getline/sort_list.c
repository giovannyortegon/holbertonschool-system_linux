#include "laps.h"
/**
 * sort_list - sort an array
 * @list:	array to sort
 * @n:		number of elements
 */
void sort_list(int **list, size_t n)
{
	size_t i, j, k;

	for (i = 0; i < n; i++)
	{
		for (j = k = i; j < n; j++)
		{
			if (list[j][0] < list[k][0])
				k = j;
		}
		swap(&*(list[i]), &*(list[k]));
		swap(&*(list[i]) + 1, &*(list[k]) + 1);
	}
}
/**
 * swap - exachange elements
 * @x:		first element
 * @y:		second element
 */
void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}
