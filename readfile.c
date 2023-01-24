#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern void processFile(FILE *);
extern void printTokenBase();

int readFile(char *fileName){
    FILE *newFile;
    newFile = fopen(fileName, "r");
    if (newFile == NULL)
        return 1;
    processFile(newFile);
    fclose(newFile);
    return 0;
}

int main(int ac, char *av[]){
    char *fileName;
    int counter;
    if (ac <= 1){
        processFile(stdin);
    } else {
        for (counter = 1; counter < ac; counter++) {
            fileName = av[counter];
            if (!strcmp(fileName, "-")){
                processFile(stdin);
            } else {
                int test = readFile(fileName);
                if (test) {
                    printf("No such file or directory [%s], errno is [%d].\n", fileName, errno);
                }
            }
        }
    }
    printTokenBase();
    return 0;
}