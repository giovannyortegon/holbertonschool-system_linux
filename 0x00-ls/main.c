#include "holberton.h"
/**
 * main - command
 * @argc:	number of arguments
 * @argv:	arguments
 * Return:	Always 0 (Success)
 */
int main(int argc, char *argv[])
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
	exit(EXIT_SUCCESS);
}
