#include "holberton.h"
/**
 * _flags - Manage flags
 * @flag:	Store all flags of command
 * @f:		All flags
 * Return:  Setup flags
 */
void _flags(char *flag, struct fg *f)
{
	int i;

	for (i = 0; flag[i]; i++)
	{
		switch (flag[i])
		{
			case 'a':
				f->fa = 1;
				break;
			case 'A':
				f->fA = 1;
				break;
			case '1':
				f->f1 = 1;
				break;
			case 'l':
				f->fl = 1;
				break;
		}
	}
}
