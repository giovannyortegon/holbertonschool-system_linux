#include "stdlib.h"
/**
 * free_arr - free string
 * @arg:	string
 * @len:	length of string
 */
void free_arr(char **arg, int len)
{
	int i;

	for (i = 0; i < len ; i++)
		free(arg[i]);

	free(arg);
}
