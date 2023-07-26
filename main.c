#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10

char *read_input_line();
void parse_input(char *line, char *args[]);
void execute_command(char *args[]);

/**
 * main -  main file
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL;
	char *args[MAX_ARGS + 1];
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("$ ");
		line = read_input_line(&len, &read);

		if (line == NULL || strcmp(line, "exit") == 0)
		{
			free(line);
			break;
		}

		parse_input(line, args);
		execute_command(args);

		free(line);
	}

	return (0);
}
