#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWord(char *str)
{
    int count = 0;
    char *token = strtok(str, ". \n\r");
    while (token != NULL)
    {
        printf("Token [%s], count [%d] \n", token, count);
        count++;
        token = strtok(NULL, " ");
    }

    return count;
}
