#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * execute_command -  executes command
 *@args: argurments
 * Return: Nothing.
 */

void execute_command(char *args[])
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}
}
