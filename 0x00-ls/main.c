#include "holberton.h"
#define MAX_LENGTH 1024

void read_dir(char *args, char *flag);

int main(int argc, char *argv[])
{
	char **args;
	char flags[5] = {0};
	int ret, str_len;
	int j = 0, x = 0;

	if (argc == 1)
	{
		read_dir(".", flags);
	}
	else
	{
		args = (char **) malloc(MAX_LENGTH * sizeof(char *));
		if (args == NULL)
		{
			perror("Failed Memory");
			exit(EXIT_FAILURE);
		}
		for (int i = 1; i < argc; i++)
		{
			ret = _strncmp(argv[i], "-", 1);
			if (ret == 0)
			{
				if (_strlen(argv[i]) == 1 )
					flags[x++] = argv[i][1];
				else
					_strcpy(flags, argv[i]);
				continue;
			}
			str_len = _strlen(argv[i]) + 1;
			if ((args[j] = (char*)malloc(str_len*sizeof(char))) == NULL)
			{
				free_arr(args, j);
				exit(EXIT_FAILURE);
			}
			
			_strcpy(args[j], argv[i]);
			j++;
		}
		for (int i = 0; i < j ; i++)
		{
			if (j != 1)
				printf("%s: \n", args[i]);
			read_dir(args[i], flags);
		}
		free_arr(args, j);
	}
	exit(EXIT_SUCCESS);
}
void read_dir(char *args, char *flag)
{
//	int fd_stat;
	int col = 0;
	DIR *dir;
	struct dirent *read = NULL;
	struct stat;
//  buf

//	fd_stat = lstat(args, &buf);
	//printf("%s\n", flag);
	if ((dir = opendir(args)) == NULL)
	{
		error_dir(errno);
		perror(args);
		return;
	}

	while ((read = readdir(dir)) != NULL)
	{
		if (strcmp(read->d_name, ".") == 0 || strcmp(read->d_name, "..") == 0)
			continue;
		if (strncmp(read->d_name, ".", 1) == 0)
			continue;
		if (col == 13)
		{
			col = 0;
			printf("\n");
		}
		fprintf(stdout, "%s\t", read->d_name);
		col += 1;
	}
	printf("\n");
	closedir(dir);
}
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

void free_arr(char **arg, int len)
{
	int i;

	for (i = 0; i < len ; i++)
	{
		free(arg[i]);
	}
	free(arg);
}
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;

	return (i);
}
char *_strcpy(char *dest, char *src)
{
        int i;

        for (i = 0; src[i] != '\0'; i++)
                dest[i] = src[i];
        dest[i++] = '\0';

        return (dest);
}
int _strncmp(char *src1, char *src2, int n)
{
	int i, flag = 0;

	for (i = 0; i <=n && src1[i]; i++)
	{
		if (src2[i] == '\0')
			break;
		else if (src1[i] == src2[i])
			continue;
		else
			flag += 1;
	}
	return (flag);
}
