#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * read_input_line -  Reads stdin
 *@len: buffer
 *@read: memory allocated to buffer
 * Return: String.
 */

char *read_input_line(size_t *len, ssize_t *read)
{
	char *line = NULL;

	*read = getline(&line, len, stdin);

	if (*read == -1)
	{
		return (NULL);
	}

	line[strcspn(line, "\n")] = '\0';
	return (line);
}
