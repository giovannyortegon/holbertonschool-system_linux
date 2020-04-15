#include "holberton.h"

void read_dir(char *args);
void error_dir(int dir);

int main(int argc, char *argv[])
{
	char **args;

	if (argc == 1)
	{
		read_dir(".");
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			if (argc > 2)
				printf("%s: \n", argv[i]);
			read_dir(argv[i]);
			if (i != argc - 1)
				printf("\n");
		}
	}
	exit(EXIT_SUCCESS);
}
void read_dir(char *args)
{
	int fd_stat;
	DIR *dir;
	struct dirent *read = NULL;
	struct stat buf;

	fd_stat = lstat(args, &buf);

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
		fprintf(stdout, "%s ", read->d_name);
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
