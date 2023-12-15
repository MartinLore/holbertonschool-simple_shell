#include "main.h"

int last_command_status = 0;

void set_last_command_status(int status)
{
	/* Save the status in a global variable or wherever you want to store it */
	last_command_status = status;
}

/**
 * Executes a command with the given arguments.
 *
 * @param argv An array of strings representing the command and its arguments.
 */

void execmd(char **argv)
{
	char *command = NULL, *actual_command = NULL;
	pid_t pid = -1;

	if (argv)
	{
		/* get the command */
		command = argv[0];

		if (strcmp(command, "exit") == 0)
		{
			if (argv[1] != NULL)
			{
				fprintf(stderr, "exit: too many arguments\n");
				return;
			}
			exit(last_command_status);
		}

		/* generate the path to this command before passing it to execve */
		actual_command = get_location(command);

		if (actual_command == NULL)
		{
			fprintf(stderr, "Command not found: %s\n", command);
			return;
		}

		/* Create a child process */
		pid = fork();

		if (pid < 0)
		{
			perror("Fork failed");
			exit(1);
		}
		else if (pid == 0)
		{
			/* Execute the actual command with execve */
			if (execve(actual_command, argv, NULL) == -1)
			{
				perror("Error:");
				_exit(1);
			}
		}
		else
		{
			/* Wait for the child process to finish */
			int status;
			waitpid(pid, &status, 0);

			/* Check if the child process exited normally and if so, get its exit status */
			if (WIFEXITED(status))
			{
				int exit_status = WEXITSTATUS(status);
				set_last_command_status(exit_status);
			}
		}

		/* Free memory only if actual_command is dynamically allocated */
		if (actual_command != command && actual_command != NULL && command != NULL && strcmp(actual_command, command) != 0)
		{
			free(actual_command);
		}
	}
=======
void execmd(char **argv) {
    char *command = NULL, *actual_command = NULL;

    if (argv) {
        pid_t pid;
        /* get the command */
        command = argv[0];

        if (strcmp(command, "exit") == 0) {
            exit(0);
        }

        /* generate the path to this command before passing it to execve */
        actual_command = get_location(command);

        if (actual_command == NULL) {
            fprintf(stderr, "Command not found: %s\n", command);
            return;
        }

        /* Create a child process */
        pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) {
            /* execute the actual command with execve */
            if (execve(actual_command, argv, NULL) == -1) {
                perror("Error:");
                _exit(1);
            }
        } else {
            /* Wait for the child process to finish */
            int status;
            waitpid(pid, &status, 0);
        }

        /* Free memory only if actual_command is dynamically allocated */
if (actual_command != command && actual_command != NULL && command != NULL && strcmp(actual_command, command) != 0) {
    free(actual_command);
>>>>>>> 27ea5e7ce5c29e6f82cf495469c38becbdf36451
}
    }
}
