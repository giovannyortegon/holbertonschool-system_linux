#include "holberton.h"
/**
 * stat_information - File modes
 * @statbuf:	strucutre of file modes
 * Return:		File modes
 */
void stat_information(struct stat *statbuf)
{
	if (S_ISDIR(statbuf->st_mode))
		printf("d");
	else if (S_ISLNK(statbuf->st_mode))
		printf("l");
	else
		printf("-");
	printf((S_IRUSR && statbuf->st_mode) ? "r" : "-");
	printf((S_IWUSR & statbuf->st_mode) ? "w" : "-");
	printf((S_IXUSR & statbuf->st_mode) ? "x" : "-");
	printf((S_IRGRP & statbuf->st_mode) ? "r" : "-");
	printf((S_IWGRP & statbuf->st_mode) ? "w" : "-");
	printf((S_IXGRP & statbuf->st_mode) ? "x" : "-");
	printf((S_IROTH & statbuf->st_mode) ? "r" : "-");
	printf((S_IWOTH & statbuf->st_mode) ? "w" : "-");
	printf((S_IXOTH & statbuf->st_mode) ? "x" : "-");
}
