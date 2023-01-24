#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char *av[]){
    char c;
    unsigned char uc;
    int ic;
    int iuc;
    c = 0X81;
    uc = 0X81;
    ic = c;
    iuc = uc;
    printf("ic %d, %x, iuc %d, %x\n", ic, ic, iuc, iuc);
    return 0;
}