#include "main.h"

/**
 * Retrieves the location of a command in the system's PATH environment variable.
 * @param command The command to search for.
 * @return The full path of the command if found, or NULL if not found.
 */

char *get_location(char *command)
{
    struct stat buffer;
    char *path, *path_copy, *path_token, *file_path;
    int command_length, directory_length;
    /* Check if the command is a full path */
    if (command[0] == '/') {
        if (stat(command, &buffer) == 0) {
            /* The command is a full path to an executable, so return a copy of the command */
            return strdup(command);
        } else {
            /* The command is a full path, but the file does not exist or is not an executable */
            return NULL;
        }
    }

    path = get_path("PATH");


    if (path) {
        /* Duplicate the path string */
		path_copy = strdup(path);
        /* Get length of the command that was passed */
		command_length = strlen(command);

		path_token = strtok(path_copy, ":");
		while(path_token != NULL)
		{
			directory_length = strlen(path_token);
            /* allocate memory for storing the command name together with the directory name */
		file_path = malloc(command_length + directory_length + 2);
		strcpy(file_path, path_token);
		strcat(file_path, "/");
		strcat(file_path, command);
		strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
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
	free(path_copy);

	if (stat(command, &buffer) == 0)
	{
		return (command);
	}
	
	return (NULL);
	}
	return (NULL);
}
