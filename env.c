#include "main.h"
char **global_env;
int i;
size_t j;

/**
 * print_env - prints all environment 
 * variables except for "SNAP" and "VALGRIND_LIB".
 */
void print_env() {
    for (i = 0; global_env[i] != NULL; i++) {
        if (strstr(global_env[i], "SNAP") == NULL 
        && strstr(global_env[i], "VALGRIND_LIB") == NULL) {
            printf("%s\n", global_env[i]);
        }
    }
}

/**
 * get_path - returns the value of the `PATH` environment variable.
 * 
 * Return: The function `get_path()` returns a 
 * pointer to a character array (string) that represents
 * the value of the `PATH` environment variable.
 */
char *get_path() {
    for (i = 0; global_env[i] != NULL; i++) {
        if (strncmp(global_env[i], "PATH=", 5) == 0) {
            return global_env[i] + 5;
        }
    }
    return NULL;
}
