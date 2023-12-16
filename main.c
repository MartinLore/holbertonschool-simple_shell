/**
 * main - function reads user input, tokenizes it,
 * and executes the corresponding command.
 * 
 * @ac: The variable `ac` represents the number of command
 * line arguments passed to the program.
 * @argv: The `argv` parameter is an array of strings that
 * represents the command-line arguments
 * passed to the program. Each element of the array is a
 * null-terminated string, and the last element
 * is always `NULL`.
 * @envp: The `envp` parameter is an array of strings
 * that represents the environment variables
 * passed to the program. Each string in the array is in the
 * format "variable=value". This parameter is
 * used to access and modify the environment variables within the program.
 * 
 * Return: The main function is returning 0.
 */
#include "main.h"

int main(int ac, char **argv, char **envp) {
    char **args = NULL;
    char *prompt = "$ ";
    char *lineptr = NULL, *lineptr_copy = NULL;
    size_t n = 0;
    ssize_t nchars_read;
    const char *delim = " \n";
    int num_tokens = 0;
    char *token;
    int i;
    int result;
    global_env = envp;

    (void)ac;
    (void)argv;

    while (1) {
        if (isatty(STDIN_FILENO))
            printf("%s", prompt);

        lineptr = NULL;
        n = 0;

        nchars_read = getline(&lineptr, &n, stdin);

        if (nchars_read == -1) {
            if (lineptr != NULL)
                free(lineptr);

            if (isatty(STDIN_FILENO))
                return 0;
            else
                return EXIT_SUCCESS;
        }

        lineptr_copy = malloc(sizeof(char) * (nchars_read + 1));
        if (lineptr_copy == NULL) {
            perror("tsh: memory allocation error");
            free(lineptr);
            lineptr = NULL;
            return -1;
        }
        strcpy(lineptr_copy, lineptr);

        token = strtok(lineptr, delim);

        while (token != NULL) {
            num_tokens++;
            token = strtok(NULL, delim);
        }
        num_tokens++;

        args = malloc(sizeof(char *) * num_tokens);

        token = strtok(lineptr_copy, delim);

        for (i = 0; token != NULL; i++) {
            args[i] = strdup(token);
            token = strtok(NULL, delim);
        }
        args[i] = NULL;

        if (args[0] == NULL) {
            for (i = 0; args[i] != NULL; i++) {
                free(args[i]);
            }
            free(args);

            free(lineptr_copy);

            free(lineptr);
            continue;
        }
        result = execmd(args);
        if (result == 127) {
            set_last_command_status(127);

            for (i = 0; args[i] != NULL; i++) {
                free(args[i]);
            }
            free(args);

            free(lineptr_copy);

            free(lineptr);
            lineptr = NULL;
            n = 0;

            exit(127);
        }

        for (i = 0; args[i] != NULL; i++) {
            free(args[i]);
        }
        free(args);

        free(lineptr_copy);

        free(lineptr);
        lineptr = NULL;
        n = 0;
    }
	return (0);
}
