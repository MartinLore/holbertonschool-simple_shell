#include "main.h"

int main(int ac, char **argv)
{
    char **args = NULL;
    char *prompt = "(Shell) $ ";
    char *lineptr = NULL, *lineptr_copy = NULL;
    size_t n = 0;
    ssize_t nchars_read;
    const char *delim = " \n";
    int num_tokens = 0;
    char *token;
    int i;

    (void)ac;
    (void)argv;

    while (1)
    {
        printf("%s", prompt);
        nchars_read = getline(&lineptr, &n, stdin);
if (nchars_read == -1)
{
    printf("Exiting shell....\n");
    free(lineptr);
    lineptr = NULL;
    return (-1);
}

        /* allocate space for a copy of the lineptr */
        lineptr_copy = malloc(sizeof(char) * (nchars_read + 1));
if (lineptr_copy == NULL)
{
    perror("tsh: memory allocation error");
    free(lineptr);
    lineptr = NULL;
            return (-1);
        }
        strcpy(lineptr_copy, lineptr);

        /* split the string (lineptr) into an array of words */
        token = strtok(lineptr, delim);

        while (token != NULL)
        {
            num_tokens++;
            token = strtok(NULL, delim);
        }
        num_tokens++;

        args = malloc(sizeof(char *) * num_tokens);
        /* Store each token in the args array */
        token = strtok(lineptr_copy, delim);

        for (i = 0; token != NULL; i++)
        {
            args[i] = strdup(token);
            token = strtok(NULL, delim);
        }
        args[i] = NULL;

        execmd(args);

        /* free up allocated memory for args and its elements */
        for (i = 0; args[i] != NULL; i++)
        {
            free(args[i]);
        }
        free(args);

        free(lineptr_copy);
    }
}