/**
 * parse_args - Parse command line arguments.
 * @cmd: The command line input string.
 * @args: An array of strings to store the parsed arguments.
 *
 * Return: The number of arguments parsed.
 */
int parse_args(char *cmd, char **args)
{
	int i = 0;
	char *token = strtok(cmd, " ");
	
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	return (i);
}
