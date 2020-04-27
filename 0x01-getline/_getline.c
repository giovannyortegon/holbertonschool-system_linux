#include "_getline.h"
/**
 * _getline - read line by line
 * @fd:			File description
 * Return:		One line of text
 */
char *_getline(const int fd)
{
	char c;
	char buffer[READ_SIZE] = {0};
	int len = 0;
	char *line;

	if (fd == -1)
		return (NULL);

	while (read(fd, &c, 1) && c != '\0')
	{
		if (c == '\n')
		{
			line = (void *) malloc(len * sizeof(char) + 1);
			if (line == NULL)
				return (NULL);
			strcpy(line, buffer);
			memset(buffer, 0, sizeof(buffer));
			len = 0;
			return (line);
		}
		buffer[len++] = c;
	}
}
