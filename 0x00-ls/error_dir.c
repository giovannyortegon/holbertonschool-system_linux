#include "stdio.h"
/**
 * error_dir - Display error of access
 * @dir:	Error number
 */
void error_dir(int dir)
{
	switch (dir)
	{
		case 2:
			fprintf(stderr, "hls: cannot access ");
			break;
		case 13:
			fprintf(stderr, "hls: cannot open directory ");
			break;
	}
}
