#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
extern char *allocStr(char *);

typedef struct {
    char *word;
    int count;
} token_t;

static token_t* base = NULL;
static int tcount = 0;

void printTokenBase(){
    for (int i = 0; i < tcount; i++){
        printf("Word: [%s], Count: [%d]\n", base[i].word, base[i].count);
    }
}

token_t* allocToken(char *s){
    // in base doesnt exist, no dpulicate token
    // increase tcount
    // extend base, reallo
    token_t *p;
    p = realloc(base, (tcount+1)*sizeof(token_t));
    if (p == NULL){
        printf("Failed to allocate memory.\n");
        return p;
    }
    base = p;
    // initilaize new area as new token
    token_t* newArea = &base[tcount]; //base+tcount == &base[tcount]
    newArea->count = 0;
    newArea->word = allocStr(s);
    if (newArea->word == NULL){
        printf("Failed to allocate memory.\n");
        return NULL;
    }    
    tcount++;
    return newArea;
}

token_t* findToken(char *s){
    // start our search from base until tcount
    //      compare string to word
    //      if match, return reference
    // return NULL;
    for (int i = 0; i < tcount; i++){
        if (!strcmp(s, base[i].word)){ //&base[i]->word 
            //true
            return &base[i]; //returns location of object, not data inside object
        } else {
            ;
        }
    }
    return NULL;
}

int processToken(char *s){
    printf("The token is [%s] \n", s);
    // our string is coming in
    // do we have the token saved?
    // yes, tell me where token is located (tp)
    // no, allocate a token (tp)
    // increment tp->count

    token_t* test1 = findToken(s);
    if (test1 == 0){
        test1 = allocToken(s);
        if (test1 == 0){
            return -1;
        }
    }
    test1->count++;    
    return 0;
}

