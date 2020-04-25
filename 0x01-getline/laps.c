#include "laps.h"
/**
 * race_state - add cars and count the laps
 * @id:		add cars
 * @size:	numbers of cars
 */
void race_state(int *id, size_t size)
{
	static int len;
	static int **num;
	int j = 0;
	size_t i, flag = 0;

	if (num == NULL && len == 0)
	{
		allocate_matrix(&num);
		len = insert_element(num, id, size);
	}
	else
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < len; j++)
			{
				if (num[j][0] == id[i])
				{
					num[j][1] += 1;
					flag = 1;
				}
			}
		}
		if (flag == 0)
			len = insert_element(num, id, size);
	}
	if (num != NULL && size != 0)
		print_matrix(num, len);
}
