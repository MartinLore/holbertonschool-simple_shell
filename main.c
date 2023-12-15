#include "main.h"
/**
 * @file main.c
 * @brief This file contains the main function for a simple shell program.
 *
 * The main function reads user input from the command line, parses it into tokens,
 * and executes the corresponding command. It uses the getline function to read
 * the input line and strtok function to split the line into tokens.
 * The tokens are stored in the argv array, which is then passed to the execmd function
 * for execution.
 *
 * @param ac The number of command line arguments.
 * @param argv An array of strings containing the command line arguments.
 * @return 0 on success, -1 on failure.
 */

int main(int ac, char **argv)
{
	char **args = NULL;
	char *prompt = "$ ";
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
		if (isatty(STDIN_FILENO))
			printf("%s", prompt);

		/* Set lineptr to NULL and n to 0 before calling getline */
		lineptr = NULL;
		n = 0;
		nchars_read = getline(&lineptr, &n, stdin);
		/* Check the return value of getline for errors or end of file */
		if (nchars_read == -1)
		{
			if (lineptr != NULL)
				free(lineptr);
			if (isatty(STDIN_FILENO))
				return (0);
			else
				return (EXIT_SUCCESS);
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
		/* If the first argument is NULL, skip this iteration */
		if (args[0] == NULL)
		{
			/* free up allocated memory for args and its elements */
			for (i = 0; args[i] != NULL; i++)
			{
				free(args[i]);
			}
			free(args);
			free(lineptr_copy);
			/* Free the buffer allocated by getline and reset lineptr and n */
			free(lineptr);
			continue;
		}
		execmd(args);
		/* free up allocated memory for args and its elements */
		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
		free(lineptr_copy);
		/* Free the buffer allocated by getline and reset lineptr and n */
		free(lineptr);
		lineptr = NULL;
		n = 0;
	}
}
