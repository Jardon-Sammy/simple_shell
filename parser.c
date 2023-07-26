#include <stdio.h>
#include <stdlib.h>
#include <string.h>
​
#define MAX_ARGS 10
​
/**
 * parse_input -  parses the input
 *@line: String from stdin
 *@args: argurments
 * Return: Nothing.
 */
​
void parse_input(char *line, char *args[])
{
    int i = 0;
    char *token = _strtok(line, " ");
​
    while (token != NULL && i < MAX_ARGS)
    {
        args[i++] = token;
        token = _strtok(NULL, " ");
    }
    args[i] = NULL;
}
