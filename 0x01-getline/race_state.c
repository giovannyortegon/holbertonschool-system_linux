#include "laps.h"
/**
 * race_state - add cars and count the laps
 * @id:		add cars
 * @size:	numbers of cars
 */
void race_state(int *id, size_t size)
{
	static int **race;
	int i, j;

	if (id == NULL && size == 0)
		free_matrix(race, 3);

	if (race == NULL)
	{
		allocate_matrix(&race, size);
		for (i = 0; i < size; i++)
		{
			race[i][0] = id[i];
			race[i][1] = 0;
		}
	}
	else
	{
		for (i = 0; i < size; i++)
		{
			if (race[i][0] == id[i])
			{
				race[i][0] = id[i];
				race[i][1] += 1;
			}
		}
	}
	print_matrix(race, size);
}
