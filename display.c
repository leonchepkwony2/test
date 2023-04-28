#include "shell.h"


/**
 * parse_args - Parse command line arguments.
 * @cmd: The command line input string.
 * @argc: An array of strings to store the parsed arguments.
 *
 * Return: The number of arguments parsed.
 */
char **parse_args(char *cmd, int *argc)
{
	int max_args = 10;
	char **argv = malloc((max_args + 1) * sizeof(char *));
	int i = 0;

	if (!argv)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	argv[0] = strtok(cmd, " ");
	i = 1;
	while (i < max_args && argv[i - 1] != NULL)
	{
		argv[i] = strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;

	*argc = i;

	return (argv);
}
/**
 * execute_command- executes a command and waits
 * @argv: The command and its arguments
 * Return: 0 on success
 */
int execute_command(char **argv)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
		waitpid(pid, &status, 0);

	return (status);
}

/**
 * main - Entry point for the shell program.
 *
 * Return: 0 on success
 */
int main(void)
{
	char *cmd = NULL;
	size_t len = 0;
	char **argv;
	int argc;

	while (1)
	{
		_putchar(PROMPT);
		fflush(stdout);

		if (getline(&cmd, &len, stdin) == -1)
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
		argv = parse_args(cmd, &argc);

		if (argv[0] != NULL && strcmp(argv[0], "exit") == 0)
		{
			free(cmd);
			free(argv);
			exit(EXIT_SUCCESS);
		}

		execute_command(argv);

		free(argv);
	}

	return (0);
}
