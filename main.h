#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#define DELIM " \t\n"
extern char **environ;
char *read_input(void);
char **token(char *line);
void free_array(char **array);
int execute(char **command,char **argv, int idx);
char *get_path(char *command);
char *get_env(char *variable);
void print_error(char *name, char *command, int idx);
void revers_str(char *str, int len);
char *_itoa(int n);
#endif 
