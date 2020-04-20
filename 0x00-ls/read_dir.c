#include "holberton.h"
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
