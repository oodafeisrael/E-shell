#include "shell.h"
/**
* main - shell program that runs shell commands, displays a prompt
* and wait for the user to type a command. A command line always ends
* with a new line. The prompt is displayed again each time a command has
* been executed. The input is the path to an executable
*Return: 0 always on success
*/
int main(void)
{
	char *strg = NULL;
	char *prompt = "s_shell$ ";
	size_t nbytes = 0;
	ssize_t num_char;

	while (1)
	{
		write(STDOUT_FILENO, prompt, 9);
		num_char = getline(&strg, &nbytes, stdin);
		if (num_char == -1)
		{
			perror("Error (getline))");
			free(strg);
			exit(EXIT_FAILURE);
		}
		if (num_char == 1 && strg[0] == '\n')
		{
			continue; /* handles empty input */
		}
		strg[num_char - 1] = '\0';
		exec_cmd(strg);
	}
	free(strg);
	return (0);

}
