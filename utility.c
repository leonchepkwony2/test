#include "myShell.h"

/**
 * _fgets - reads a line from a file stream and stores it into a string
 * @str: the buffer to store the read line
 * @num: the maximum number of characters to be read
 * @stream: the file stream to read from
 *
 * Return: On success, the pointer to the buffer containing the read line.
 *         If end-of-file occurs before any characters are read, the function
 *         returns NULL and the buffer contents remain unchanged.
 */
char *_fgets(char *str, int num, FILE *stream)
{
	char *result = fgets(str, num, stream);

	if (result == NULL)
		return (NULL);

	char *newline_pos = _strchr(str, '\n');

	if (newline_pos != NULL)
	{
		*newline_pos = '\0';
	}
	else
	{
		int c;

		while ((c = _getchar()) != '\n' && c != EOF)
		{
		}
	}

	return (str);
}
