#include "laps.h"
/**
 * allocate_matrix - allocate memory to the array
 * @arr:	array
 * @col:	columns of the array
 */
void allocate_matrix(int ***arr, size_t col)
{
	size_t i;
	int **ptr;

	ptr = (int **) malloc(col * sizeof(int *));
	if (ptr == NULL)
		exit(EXIT_FAILURE);

	for (i = 0; i < col; i++)
	{
		ptr[i] = (int *)malloc(2 * sizeof(int));
		if (ptr[i] == NULL)
		{
			free_matrix(ptr, i);
			exit(EXIT_FAILURE);
		}
		memset(ptr[i], 0, 2 * sizeof(int));
	}
	*arr = ptr;
}
