#include <stdio.h>
#include <stdlib.h>
extern int processToken(char *);

// externed process Token
// int processToken(char *token)
// {
//     printf("The token is [%s] \n", token);
//     return 0;
// }

int allowedTable[256] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

int fetchToken(FILE *fp, int (*func)(char *))
{
    int x;
    char s[1000];
    char cur;
    int counter;
    int numToken;
    int state;

    counter = 0;
    numToken = 0;

    do
    {
        cur = fgetc(fp);
        state = allowedTable[cur];
        if (state == 1 || cur == EOF)
        //if (cur == ' ' || cur == EOF || cur == '.' || cur == '\n' || cur =='\r')
        {
            if (counter > 0)
            {
                s[counter] = 0;
                numToken++;
                func(s);
                counter = 0; // initial condition
            }
        }
        else
        {
            s[counter] = cur;
            counter++;
        };
    } while (cur != EOF);
    return numToken;
}

void processFile(FILE *fp)
{
    int check;
    check = fetchToken(fp, processToken);
    if (check == -1){
        exit(1);
    }
    printf("Token(s) found: [%d]\n", check);
}