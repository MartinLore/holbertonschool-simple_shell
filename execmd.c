#include "main.h"
/**
 * Executes a command with the given arguments.
 *
 * @param argv An array of strings representing the command and its arguments.
 */
void execmd(char **argv){
    char *command = NULL, *actual_command = NULL;


    if (argv){
        /* get the command */
        command = argv[0];


        if (strcmp(command, "exit") == 0)
        {
            exit(0);
        }


        /* generate the path to this command before passing it to execve */
        actual_command = get_location(command);


        /* Create a child process */
        pid_t pid = fork();


        if (pid < 0)
        {
            perror("Fork failed");
            exit(1);
        }
        else if (pid == 0)
        {
            /* execute the actual command with execve */
            if (execve(actual_command, argv, NULL) == -1){
                perror("Error:");
                _exit(1);
            }
        }
        else
        {
            /* Wait for the child process to finish */
            int status;
            waitpid(pid, &status, 0);
        }
    }
}
