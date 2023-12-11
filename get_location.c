#include "main.h"

/**
 * Retrieves the location of a command in the system's PATH environment variable.
 * @param command The command to search for.
 * @return The full path of the command if found, or NULL if not found.
 */

char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;
	path = getenv("PATH");
	if (path)
	{
        /* Duplicate the path string */
		path_copy = strdup(path);
        /* Get length of the command that was passed */
		command_length = strlen(command);
       /* Get the first directory in the path */
		path_token = strtok(path_copy, ":");
		while(path_token != NULL)
		{
            /* Get the length of the directory*/
			directory_length = strlen(path_token);
            /* allocate memory for storing the command name together with the directory name */
		file_path = malloc(command_length + directory_length + 2); /* +2 for the '/' and the '\0' */
            /* copy the directory name into the file_path */
		strcpy(file_path, path_token);
		strcat(file_path, "/");
		strcat(file_path, command);
		strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
                /* return value of 0 means success implying that the file_path is valid*/
               /* free up allocated memory before returning your file_path */
				free(path_copy);
				return (file_path);
			}
			else
			{
                /* free up the file_path memory to check for another path*/
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
        /* free up the path_copy memory before returning NULL */
	free(path_copy);
        /* return NULL if the command is not found in any of the directories */
	if (stat(command, &buffer) == 0)
	{
		return (command);
	}
	return (NULL);
	}
	return (NULL);
}
