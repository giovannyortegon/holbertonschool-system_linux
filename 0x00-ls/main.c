#include "holberton.h"

void *usr_information(char *src, struct stat *statbuf, struct stat *_dir)
void *grp_information(char *src, struct stat *statbuf, struct stat *_dir);
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
	char File[60] = {0};
	int i, col = 0, c_fl = 0;
	DIR *dir;
	struct fg f = {0, 0, 0, 0};
	struct dirent *read = NULL;
	struct stat _dir, file;

	lstat(args, &_dir);
	if ((dir = opendir(args)) == NULL)
	{
		perror(args);
		error_dir(errno);
		return;
	}

	_flags(flag, &f);

	while ((read = readdir(dir)) != NULL)
	{
		lstat(read->d_name, &file);
		if (f.fa == 0 && read->d_type == DT_DIR)
			if (_strncmp(read->d_name, ".", 1) == 0 ||
				_strncmp(read->d_name, "..", 1) == 0)
				continue;
		if (f.fA == 0 && f.fa == 0)
		{
			if (_strncmp(read->d_name, ".", 1) == 0)
				continue;
		}
		else if (col == 13 && f.f1 == 0 )
		{
			col = 0;
			printf("\n");
		}
		if (f.fl == 0)
			fprintf(stdout, "%s\t", read->d_name);
		else
		{
			c_fl += 1;
			print_dir(read->d_name, &file, &_dir);
			fprintf(stdout, "%s\t", read->d_name);
		}
		fprintf(stdout, "%s\t", File);
		col += 1;
		if (f.f1 == 1 || f.fl == 1)
			printf("\n");
	}
	if (f.fl == 1)
			printf("tota %d\n", c_fl);

	printf("\n");
	closedir(dir);
}
void *usr_infomation(char *src, struct stat *statbuf, struct stat *_dir)
{
	struct passwd *usr;
	struct group *grp;

	if (S_ISDIR(statbuf->st_mode))
		printf("d");
	else
		printf("-");
                if (statbuf->st_mode && S_IRUSR)
                        printf("r");
                else
                        printf("-");
                if (statbuf->st_mode && S_IWUSR)
                        printf("w");
                else
                        printf("-");
                if (statbuf->st_mode && S_IXUSR)
                        printf("x");
                else
                        printf("-");
                usr = getpwuid(_dir->st_uid);
				grp = getgrgid(_dir->st_gid);
                                printf(" %d %s %s %d %s\n",
                                statbuf->st_nlink,
                                usr->pw_name,
								grp->gr_name,
                                statbuf->st_size,
                                ctime(&_dir->st_mtime));
}
/**
 * _flags - Manage flags
 * @flag:	Store all flags of command
 * @f:		All flags
 * Return:  Setup flags
 */
void *_flags(char *flag, struct fg *f)
{
	for (int i = 0; flag[i]; i++)
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
