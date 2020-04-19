#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/**
 * _strcmp - compare two strings
 * @src1:	First srting
 * @src2:	Two strings
 * Return: If is 0 are equals
 */
int _strcmp(char *src1, char *src2)
{
	int i, flag = 0;

	for (i = 0; src1[i]; i++)
	{
		if (src2[i] == '\0')
		{
			flag += 1;
			break;
		}
		else if (src1[i] == src2[i])
			continue;
		else
			flag += 1;
	}
	return (flag);
}
