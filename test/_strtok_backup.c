#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * _strtok -  Splits Strings and returns an array
 * of each word of the string.
 *@str: String to be split
 *@del: delimiter
 * Return: Returns a String.
 */

char *_strtok(char *str, const char *del)
{
	static char *next_token;

	if (str)
	{
		next_token = str;
	}
	if (!next_token)
	{
		return (NULL);
	}
	str = next_token;
	while (*next_token)
	{
		if (strchr(del, *next_token))
		{
			*next_token++ = '\0';
			break;
		}
		next_token++;
	}
	return (*str ? str : NULL);
}

