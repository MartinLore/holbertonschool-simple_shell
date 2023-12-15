#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int execmd(char **argv);
char *get_location(char *command);
void set_last_command_status(int status);
extern char **global_env;
void print_env();
char *get_path();
void bubble_sort(char **env, int n);