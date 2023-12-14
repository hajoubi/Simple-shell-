#include "main.h"




char *get_path(char *command){
        int i;
        char *path, *full_command, *dir;
        struct stat st;
        for (i = 0; command[i]; i++)
        {
                if (command[i] == '/')
                {
                        if(stat(command, &st) == 0)
                                return (strdup(command));
                }
                return(NULL);
        }

        path = get_env("PATH");
        if (!path)
                return (NULL);
        dir = strtok(path, ":");
        while(dir)
        {
                full_command = malloc(strlen(dir) + strlen(command) + 2);
                if (full_command)
                {
                        strcpy(full_command, dir);
                        strcat(full_command, "/");
                        strcat(full_command, command);
                        if(stat(full_command, &st) == 0)
                        {
                                free(path);
                                return(full_command);
                        }
                free(full_command);
                full_command = NULL;
                dir = strtok(NULL, ":");
                }
        }
        free(path);
        return (NULL);
}

