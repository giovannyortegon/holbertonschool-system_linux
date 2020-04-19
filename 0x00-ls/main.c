#include "holberton.h"
#define MAX_LENGTH 1024

void read_dir(char *args, char *flag);

int main(int argc, char *argv[])
{
	char **args;
	char flags[5] = {0};
	int ret, str_len, len = 0;
	int j = 0, x = 0, y;

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
			str_len = _strlen(argv[i]);
			if (ret == 0)
			{
				len += 1;
				if (str_len >= 2 )
				{
					for (y = 1; y < str_len;x++, y++)
						flags[x] = argv[i][y];
				}
				continue;
			}
			if ((args[j] = (char*)malloc(str_len + 1*sizeof(char))) == NULL)
			{
				free_arr(args, j);
				exit(EXIT_FAILURE);
			}
			_strcpy(args[j], argv[i]);
			j++;
			
		}
		if (len != 0 && j == 0)
			read_dir(".", flags);
		else
		{
			for (int i = 0; i < j ; i++)
			{
				if (j != 1)
					printf("%s: \n", args[i]);
				read_dir(args[i], flags);
				if (i < j -1)
					printf("\n");
			}
		}
		free_arr(args, j);
	}
	exit(EXIT_SUCCESS);
}
void read_dir(char *args, char *flag)
{
//	int fd_stat;
	int i, col = 0;
	int f1 = 0, fa = 0, fA = 0;
	DIR *dir;
	struct dirent *read = NULL;
	struct stat;
//  buf

//	fd_stat = lstat(args, &buf);
	if ((dir = opendir(args)) == NULL)
	{
		error_dir(errno);
		perror(args);
		return;
	}
	for (i = 0; flag[i]; i++)
	{
		switch(flag[i])
		{
			case 'a':
				fa = 1;
				break;
			case 'A':
				fA = 1;
				break;
			case '1':
				f1 = 1;
				break;
		}
	}
	printf("-a: %d, -1: %d -A: %d\n", fa, f1, fA);
	while ((read = readdir(dir)) != NULL)
	{
		if (fa == 0 && read->d_type == DT_DIR)
			if (_strncmp(read->d_name, ".", 1) == 0 ||
				_strncmp(read->d_name, "..", 1) == 0)
				continue;
		if (fA == 0 && fa == 0)
		{
			if (_strncmp(read->d_name, ".", 1) == 0)
				continue;
		}
		else if (col == 13 && f1 == 0 )
		{
			col = 0;
			printf("\n");
		}
		fprintf(stdout, "%s\t", read->d_name);
		col += 1;
		if (f1 == 1)
			printf("\n");
	}
	printf("\n");
	closedir(dir);
}
