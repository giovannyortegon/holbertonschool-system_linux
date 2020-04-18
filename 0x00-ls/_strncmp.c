/**
 * _strncmp - compare n characters
 * @src1: first string
 * @src2: second string
 * @n: number of string
 * Return: 0 if it is equal
 */
int _strncmp(char *src1, char *src2, int n)
{
	int i, flag = 0;

	for (i = 0; i <= n && src1[i]; i++)
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
