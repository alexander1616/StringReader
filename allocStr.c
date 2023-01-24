#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *allocStr(char *s){
    int size;
    for (size = 0; s[size] !=0; size++);
    size ++;
    char *p;
    p = malloc(size);
    if (p == NULL){
        return p;
    }    
    int i = 0;
    while (i < size){
        p[i] = s[i];
        i++;
    } 
    return p;
}

char *allocStrPro(char *s){
    int size = strlen(s); //strlen does not count the null
    char *p;
    p = malloc(size + 1); //malloc account for size + null
    if (p == NULL){
        return p;
    }
    strcpy(p, s); //str copy (destination, source) copies null
    return p;
}