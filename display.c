#include "shell.h"

extern char **environ;


/**
 * main - Entry point for the shell program.
 *
 * Return: 0 on success
 */
int main(void)
{
	char cmd[MAX_CMD_LENGTH];
	char *argv[] = {NULL, NULL};
	int status;
	
	while (1)
	{
		_putchar(PROMPT);
		fflush(stdout);
		if (_fgets(cmd, MAX_CMD_LENGTH, stdin) == NULL)
		{
			if (_feof(stdin))
			{
				_putchar('\n');
				exit(EXIT_SUCCESS);
			}
			perror("fgets");
			exit(EXIT_FAILURE);
		}
		cmd[_strcspn(cmd, "\n")] = '\0';
		argv[0] = cmd;
		pid_t pid = fork();
		
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execve(cmd, argv, environ) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
	return (0);
}
