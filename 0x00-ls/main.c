#include "holberton.h"
/**
 * main - command
 * @argc:	number of arguments
 * @argv:	arguments
 * Return:	Always 0 (Success)
 */
void read_all(int argc, char **argv);
int main(int argc, char *argv[])
{
	read_all(argc, argv);
	exit(EXIT_SUCCESS);
}
/**
 * read_all - command
 * @argc:	number of arguments
 * @argv:	arguments
 * Return:	Always 0 (Success)
 */
void read_all(int argc, char **argv)
{
	char **args, flags[5] = {0};
	int i, ret, str_len, len = 0, j = 0, x = 0, y;

	if (argc == 1)
		read_dir(".", flags);
	else
	{
		args = (char **) malloc(MAX_LENGTH * sizeof(char *));
		if (args == NULL)
		{
			perror("Failed Memory");
			exit(EXIT_FAILURE);
		}
		for (i = 1; i < argc; i++)
		{
			ret = _strncmp(argv[i], "-", 1);
			str_len = _strlen(argv[i]);
			if (ret == 0)
			{
				len += 1;
				if (str_len >= 2)
				{
					for (y = 1; y < str_len; x++, y++)
						flags[x] = argv[i][y];
				}
				continue;
			}
			args[j] = (char *)malloc(str_len + 1 * sizeof(char));
			if (args[j] == NULL)
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
			for (i = 0; i < j ; i++)
			{
				if (j != 1)
					printf("%s: \n", args[i]);
				read_dir(args[i], flags);
				if (i < j - 1)
					printf("\n");
			}
		}
		free_arr(args, j);
	}
}
/**
 * read_dir - read directories
 * @args:	Arguments of directories
 * @flag:	Flags
 * Return:	Directories
 */
void read_dir(char *args, char *flag)
{
	int col = 0, c_fl = 0;
	DIR *dir;
	struct fg f = {0, 0, 0, 0};
	struct dirent *read = NULL;
	struct stat _dir, file;
	struct passwd *usr;
	struct group *grp;

	lstat(args, &_dir);
	dir = opendir(args);
	if (dir == NULL)
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
		else if (col == 13 && f.f1 == 0)
		{
			col = 0;
			printf("\n");
		}
		if (f.fl == 0)
			fprintf(stdout, "%s\t", read->d_name);
		else
		{
			c_fl += 1;
			stat_information(&file);
			usr = getpwuid(_dir.st_uid);
			grp = getgrgid(_dir.st_gid);
			printf(" %ld %s %s %ld %s",
					file.st_nlink,
					usr->pw_name,
					grp->gr_name,
					file.st_size,
					ctime(&_dir.st_mtime));
			fprintf(stdout, "%s\t", read->d_name);
		}
		col += 1;
		if (f.f1 == 1 || f.fl == 1)
			printf("\n");
	}
	printf("\n");
	closedir(dir);
}
