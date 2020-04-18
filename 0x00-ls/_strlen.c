/**
 * _strlen - measure length of a string
 * @str: String to measure
 * Return: number of characters
 */
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}
