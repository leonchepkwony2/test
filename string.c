#include "myShell.h"

/**
 * _strlen - returns the length of a string
 * @str: the string to be measured
 *
 * Return: the length of the string
 */
size_t _strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}
/**
 * _strchr - locates a character in a string
 * @str: the string to be searched
 * @c: the character to search for
 *
 * Return: a pointer to the first occurrence of the character,
 *         or NULL if the character is not found
 */
char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return ((char *) str);
		}
		str++;
	}
	if (c == '\0')
	{
		return ((char *) str);
	}
	return (NULL);
}
/**
 * _getchar - reads a single character from stdin
 *
 * Return: the character read, or EOF on end of file or error
 */
int _getchar(void)
{
	static char buf[BUFSIZ];
	static char *bufp = buf;
	int n = 0;
	
	if (n == 0)
	{
		n = read(0, buf, sizeof(buf));
		bufp = buf;
	}
	return ((--n >= 0) ? (unsigned char)*bufp++ : EOF);
}
/**
 * _strcmp - compares two strings
 * @str1: the first string to compare
 * @str2: the second string to compare
 *
 * Return: an integer less than, equal to, or greater than zero if str1 is
 *         found, respectively, to be less than, to match, or be greater
 *         than str2.
 */
int _strcmp(const char *str1, const char *str2)
{
	int i = 0;
	
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return ((str1[i] < str2[i]) ? -1 : 1);
		}
		i++;
	}
	if (str1[i] == '\0' && str2[i] == '\0')
	{
		return (0);
	}
	else
	{
		return ((str1[i] < str2[i]) ? -1 : 1);
	}
}
