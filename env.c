#include "main.h"

/**
 * print_env - Prints the environment, excluding specific variables.
 * @env: The environment variable.
 */
void print_env(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		if (strstr(env[i], "SNAP") == NULL && strstr(env[i], "VALGRIND_LIB") == NULL)
		{
			printf("%s\n", env[i]);
		}
	}
}

/**
* get_path - Retrieves the PATH environment variable.
* @env: The environment variable.
* Return: The value of the PATH variable.
*/
char *get_path(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			return (env[i] + 5);
		}
	}
	return (NULL);
}
