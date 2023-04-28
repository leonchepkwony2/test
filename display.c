#include "shell.h"

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
	char *newline_pos;
	char *result = fgets(str, num, stream);
	
	if (result == NULL)
		return (NULL);

	 newline_pos = _strchr(str, '\n');

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


/**
 * _feof - checks if end-of-file indicator is set for a stream
 *
 * @stream: pointer to the stream to check
 *
 * Return: 1 if end-of-file indicator is set, 0 otherwise
 */
int _feof(FILE *stream)
{
	long pos = ftell(stream);
	int c = getc(stream);
	
	fseek(stream, pos, SEEK_SET);
	if (c == EOF && ferror(stream))
		return (1);
	else
		return (0);
}
