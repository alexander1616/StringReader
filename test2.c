#include <stdio.h>
#include <stdlib.h>

void dumpbuffer(void * p, int size){
    unsigned char uc;
    unsigned char * ucp = p;
    int i;
    for (i=0; i<size; i++){
        uc = *ucp++;
        printf("%02x ", uc);
    }
    printf("\n");
}

int main(int ac, char *av []){
    char c;
    unsigned short s;
    long l;
    long ul;
    float f;

    l = 16;
    f = 16;
    // c = -1;
    // s = c;
    // l = s;
    // ul = s;

    dumpbuffer(&l, sizeof(l));
    dumpbuffer(&f, sizeof(f));
    // printf("%x\n", ul);
    // dumpbuffer(&ul, sizeof(ul));
    // dumpbuffer(&s, sizeof(s));
    // dumpbuffer(&l, sizeof(l));
    return 0;
}
