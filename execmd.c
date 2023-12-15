#include "main.h"

int last_command_status = 0;

void set_last_command_status(int status) {
    /* Save the status in a global variable or wherever you want to store it */
    last_command_status = status;
}

/**
 * Executes a command with the given arguments.
 *
 * @param argv An array of strings representing the command and its arguments.
 */
int execmd(char **argv) {
    char *command = NULL, *actual_command = NULL;
    pid_t pid = -1;

    if (argv) {
        /* get the command */
        command = argv[0];

        if (strcmp(command, "exit") == 0) {
            if (argv[1] != NULL) {
                fprintf(stderr, "exit: too many arguments\n");
                return 1;
            }
            
            exit(last_command_status);
        }
        if (strcmp(command, "env") == 0) {
    print_env();
    return 0;
}

        /* generate the path to this command before passing it to execve */
        actual_command = get_location(command);

        if (actual_command == NULL) {
            fprintf(stderr, "./hsh: 1: %s: not found\n", command);
            return 127;
        }

        /* Create a child process */
        pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) {
            /* Execute the actual command with execve */
            if (execve(actual_command, argv, NULL) == -1) {
                perror("Error:");
                _exit(1);
            }
        } else {
            /* Wait for the child process to finish */
            int status;
            waitpid(pid, &status, 0);

            /* Check if the child process exited normally and if so, get its exit status */
            if (WIFEXITED(status)) {
                int exit_status = WEXITSTATUS(status);
                set_last_command_status(exit_status);
            }
        }

        /* Free memory only if actual_command is dynamically allocated */
if (actual_command != command && actual_command != NULL) {
    free(actual_command);
}
    }

    return 0;
}