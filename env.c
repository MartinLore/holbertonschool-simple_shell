#include "main.h"
char **global_env;
int i;
size_t j;

void print_env() {
    for (i = 0; global_env[i] != NULL; i++) {
        if (strstr(global_env[i], "SNAP") == NULL && strstr(global_env[i], "VALGRIND_LIB") == NULL) {
            printf("%s\n", global_env[i]);
        }
    }
}

char *get_path() {
    for (i = 0; global_env[i] != NULL; i++) {
        if (strncmp(global_env[i], "PATH=", 5) == 0) {
            return global_env[i] + 5;
        }
    }
    return NULL;
}
