#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10

int main(void)
{
	pid_t pid;
	int status;
	char *line = NULL;
	char *args[MAX_ARGS + 1];
	size_t len = 0;
	ssize_t read;
	char *env[] = {NULL};

	while (1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			break; 
		}

		line[strcspn(line, "\n")] = '\0';

		if (strcmp(line, "exit") == 0)
		{
			break; 
		}

		int i = 0;
		char *token = strtok(line, " ");

		while (token != NULL && i < MAX_ARGS)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		pid = fork();

		if (pid < 0)
		{
			perror("fork");
			return (1);
		}
		else if (pid == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				perror("execvp");
				return (1);
			}
		}
		else
		{
			wait(&status);
		}
	}

	free(line);
	return (0);
}

