#include "myShell.h"

/**
 * handle_redirections - Handles shell redirections
 *
 * @args: Array of arguments to the command
 * @num_args: Number of arguments
 *
 * Return: void
 */
void handle_redirections(char **args, int num_args)
{
	int i, input_fd = 0, output_fd = 0;
	char *input_file = NULL, *output_file = NULL;

	/* Check for input and output redirection */
	for (i = 0; i < num_args; i++)
	{
		if (_strcmp(args[i], "<") == 0)
		{
			input_file = args[i + 1];
			input_fd = open(input_file, O_RDONLY);
			if (input_fd == -1)
			{
				perror(input_file);
				exit(EXIT_FAILURE);
			}
			dup2(input_fd, STDIN_FILENO);
			close(input_fd);
			args[i] = NULL;
		}
		else if (_strcmp(args[i], ">") == 0)
		{
			output_file = args[i + 1];
			output_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (output_fd == -1)
			{
				perror(output_file);
				exit(EXIT_FAILURE);
			}
			dup2(output_fd, STDOUT_FILENO);
			close(output_fd);
			args[i] = NULL;
		}
	}
}
