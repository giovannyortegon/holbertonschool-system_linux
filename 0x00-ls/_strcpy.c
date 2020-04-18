/**
 * _strcpy - Copy a string
 * @dest:	Destin to copy
 * @src:	Original string
 * Return:	String
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i++] = '\0';

	return (dest);
}
