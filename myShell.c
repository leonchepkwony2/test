#include "myShell.h"

/**
 * main - Entry point for the myShell program
 *
 * Return: Always (0)
 */

int main(void)
{
	char *input;
	char *args[MAX_INPUT / 2 + 1];
	int status;
	pid_t pid;
	int num_args;

	while (1)
	{
		display_prompt();
		fflush(stdout);

		input = (char *)malloc(sizeof(char) * MAX_INPUT);
		if (_fgets(input, MAX_INPUT, stdin) == NULL)
		{
			perror("Error reading input");
			continue;
		}
		num_args = 0;
		args[num_args] = strtok(input, " \n");

		while (args[num_args] != NULL && num_args < MAX_INPUT / 2)
		{
			num_args++;
			args[num_args] = strtok(NULL, " \n");
		}

		if (num_args > 0 && _strcmp(args[0], "exit") == 0)
		{
			exit(0);
		}

		pid = fork();
		if (pid < 0)
		{
			perror("Error forking");
		}
		else if (pid == 0)
		{
			execvp(args[0], args);
			perror("Error executing command");
			exit(1);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
		free(input);
	}
	return (0);
}
