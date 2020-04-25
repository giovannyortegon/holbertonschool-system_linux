#include "laps.h"
/**
 * insert_element - add a new element in array
 * @m:		array of cars and number laps
 * @ptr:	array of cars
 * @n:		length of array of cars
 * Return:	number of cars
 */
int insert_element(int **m, int *ptr, size_t n)
{
	size_t i;
	static size_t j;

	for (i = 0; i < n; i++, ++j)
	{
		m[j][0] = ptr[i];
		m[j][1] = 0;
		printf("Car %d joined the race\n", m[j][0]);
	}
	sort_list(m, j);
	return (j);
}
