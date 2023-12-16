#include "main.h"
    int last_command_status = 0;

/**
 * set_last_command_status - sets the value of the
 *  last command status variable.
 * 
 * @status: The parameter "status" 
 * is an integer value that represents the status of the last
 * command executed.
 */
void set_last_command_status(int status) {
    last_command_status = status;
}

/**
 * execmd - Checks if a given path is an executable
 * @argv:
 *
 * Return: If it is an executable file or not
 */

int execmd(char **argv) {
    char *command = NULL, *actual_command = NULL;
    pid_t pid = -1;

    if (argv) {
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
        actual_command = get_location(command);

        if (actual_command == NULL) {
            fprintf(stderr, "./hsh: 1: %s: not found\n", command);
            return 127;
        }
        pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) {
            if (execve(actual_command, argv, NULL) == -1) {
                perror("Error:");
                _exit(1);
            }
        } else {
            int status;
            waitpid(pid, &status, 0);

            if (WIFEXITED(status)) {
                int exit_status = WEXITSTATUS(status);
                set_last_command_status(exit_status);
            }
        }

if (actual_command != command && actual_command != NULL) {
    free(actual_command);
}
    }

    return 0;
}