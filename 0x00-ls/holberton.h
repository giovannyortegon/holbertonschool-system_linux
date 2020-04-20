#ifndef __HOLBERTON_H__
#define __HOLBERTON_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

#define MAX_LENGTH 1024
/**
 * struct fg - list dates about pet
 * @fa: all
 * @fA: only regular hiden file
 * @f1: nextline
 * @fl: list
 */
struct fg
{
	int fa, fA, f1, fl;
};

void error_dir(int dir);
void free_arr(char **arg, int len);
void _flags(char *flag, struct fg *f);
void stat_information(struct stat *statbuf);
void read_dir(char *args, char *flag);
char *_strcpy(char *dest, char *src);
int _strlen(char *str);
int _strncmp(char *src1, char *src2, int n);

#endif /* HOLBERTON.H */
