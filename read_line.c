#include "main.h"



char *read_input(void){

        char *input = NULL;
        size_t buffer = 0;
        ssize_t n;
        if (isatty(1)){
                write(1, "$ ",2);
        }
        n = getline(&input, &buffer, stdin);
        if (n == -1){
            free(input);        
            return(NULL);
        }
        return (input);

}

