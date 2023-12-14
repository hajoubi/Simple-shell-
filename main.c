#include "main.h"

int main(int ac, char **argv){
        
char *line = NULL;
int status = 0;
int idx = 0;
char **command = NULL;
(void) ac;
while(1){
        line = read_input();
        if (line == NULL){
                if (isatty(1)){
                write(1,"\n",1);
                }
                return(status);
        }
        ++idx;
        command = token(line);
        if (!command)
                continue;
        status = execute(command, argv, idx);


}
}

