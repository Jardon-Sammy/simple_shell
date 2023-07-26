#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _strtok -  Splits Strings and returns an array
 * of each word of the string.
 *@str: String to be split
 *@del: delimiter
 * Return: Returns a String.
 */

char *_strtok(char *str, char *del)
{
	int count = 0;
	char *token = NULL;

	while (str[count] != '\0')
	{

		if (str[count] == *del)
		{
			token = malloc(sizeof(char) * (count + 1));
			strncpy(token, str, count);
			token[count] = '\0';

		}
		count++;
	}
	return (token);
}
