#include "main.h"


char **token(char *line){

        char *temp = NULL;
        char *token = NULL;
        int i = 0, count = 0;
        char **command = NULL;
        if (!line){
                return(NULL);
        }
        temp = strdup(line);
        token = strtok(temp, DELIM);
        if (token == NULL){
                free (temp);
                temp = NULL;
                free (line);
                line = NULL;
        }
        while(token){
                count ++;
                token = strtok(NULL, DELIM);
        }
        free(temp);
        temp = NULL;
        command = malloc(sizeof(char *) * (count + 1));
        if (!command){
                free(line);
                return (NULL);
        }
        token = strtok(line, DELIM);
        while(token){
                command[i] = strdup(token);
                token = strtok(NULL, DELIM);
                i++;
        }
        free(line);
        line = NULL;
        command[i] = NULL;
        return (command);
}

