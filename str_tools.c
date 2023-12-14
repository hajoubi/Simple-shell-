#include "main.h"



char *_itoa(int n)
{
        char buffer[20];
        int i = 0;

        if (n == 0)
        
                buffer[i++] = '0';
        else
        {
                while (n > 0)
                {
                        buffer[i++] = (n % 10) + '0';
                        n /= 10;
                }
        }
        buffer[i] = '\0';
        revers_str(buffer, i);
        return(strdup(buffer));
}

void revers_str(char *str, int len)
{
        char temp;
        int start;
        int end = len -1;
        while(start < end)
        {
                temp = str[start];
                str[start] = str[end];
                str[end] = temp;
                start ++;
                end --;
        }
}

