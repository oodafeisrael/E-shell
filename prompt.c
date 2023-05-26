#include "shell.h"
/**
* exec_cmd - This function executes the command entered by the users
* @strg: Command argument entered by the user in the shell
*/
void exec_cmd(char *strg)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		char **args = (char **)malloc(2 * sizeof(char *));

		args[0] = strg;
		args[1] = NULL;
		/* child process */
		execve(strg, args, NULL);
		perror("exec");
		exit(EXIT_FAILURE);
	} else
	{
		/* parent process */
		waitpid(child_pid, &status, 0);
	}
}
