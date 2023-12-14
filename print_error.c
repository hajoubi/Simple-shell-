#include "main.h"


void print_error(char *name, char *command, int idx)
{
        char *index;
        char mssg[] = ": not found\n";
        index = _itoa(idx);
        write(STDERR_FILENO, name, strlen(name));
        write(STDERR_FILENO, ": ", 2);
        write(STDERR_FILENO, index, strlen(index));
        write(STDERR_FILENO, ": ", 2);
        write(STDERR_FILENO, command, strlen(command));
        write(STDERR_FILENO, mssg, strlen(mssg));
        free(index);
}

