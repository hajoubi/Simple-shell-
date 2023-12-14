#include "main.h"



char *get_env(char *variable){

        char *temp, *key, *value, *env;
        int i;

        for (i = 0; environ[i]; i++)
        {
                temp = strdup(environ[i]);
                key = strtok(temp, "=");
                if (strcmp(key, variable) == 0)
                {
                        value = strtok(NULL, "\n");
                        env = strdup(value);
                        free(temp);
                        return (env);
                }
                free(temp);
                temp =NULL;
        }
        return (NULL);
}

