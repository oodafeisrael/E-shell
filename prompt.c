#include "shell.h"
/**
* main - Shell program that runs shell commands, Displays a prompt and wait for the
* user to type a command. A command line always ends with a new line.
* The prompt is displayed again each time a command has been executed.
* the input is the path to an executable
* Return: 0 always on success
*/
int main()
{
	char *strg = NULL;
	char *prompt = "s_shell$";
	size_t nbytes = 0;
	ssize_t num_char;
	pid_t child_pid;
	int status;

	while (1)
	{
		write(STDOUT_FILENO, prompt, 8); /* displays the prompt */
		num_char = getline(&strg, &nbytes, stdin); /* gets users input */
		if (num_char == -1)
		{
			perror("Error (getline)");
			free(strg);
			exit(EXIT_FAILURE);
		}
		if (num_char == 1 && strg[0] == '\n')
		{
			continue; /* this handles empty input */
		}
		strg[num_char - 1] = '\0';
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			/* child process */
			char **args = (char **)malloc(2 * sizeof(char *));
			args[0] = strg;
			args[1] = NULL;
			execve(strg, args, NULL);
			perror("exec");
		} else {
			/* parent process */
			waitpid(child_pid, &status, 0);
		}
	}
	free(strg);
	return (0);

}
