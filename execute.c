#include "main.h"


int execute(char **command, char **argv, int idx){

        pid_t child;
        int status;
        char *full_command;
        full_command = get_path(command[0]);
        if(!full_command)
        {
                print_error(argv[0], command[0], idx);
                free_array(command);
                return(0);
        }



        child = fork();
        if (child == 0)
        {
                if (execve(full_command, command, environ) == -1)
                {
                        free(full_command);
                        full_command = NULL;
                        free_array(command);
                }
                else
                {
                        waitpid(child, &status, 0);
                        free_array(command);
                        free(full_command);
                        full_command = NULL;
                }

        }
        return (WEXITSTATUS(status));
}

