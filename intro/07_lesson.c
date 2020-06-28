#include <stdio.h>
#include <stdlib.h>

int main() {
    // unsigned int q = 2151686160;
    // printf("%%d: %d\n", q);
    // printf("%%u: %u\n", q);
    // printf("%%o: %o\n", q);
    // printf("%%x: %x\n", q);
    // printf("%%hhx: %hhx\n", q);
    // printf("%%hhu: %hhu\n", q);

    // (i)
    unsigned int i = 261;
    int *ip = &i;
    char *cp = &i;

    // (ii)
    printf("(ii)\n");
    printf("ip: %p, ip points to: %u\n", ip, *ip);
    printf("cp: %p, cp points to: %u\n", cp, *cp);

    // (iii)
    printf("\n(iii)\n");
    printf("i in decimal: %u\n", i);
    printf("i in hex: %x\n", i);

    // (iv)
    printf("\n(iv)\n");
    int byte;
    for(byte=0; byte<4; byte++) {
        printf("Byte %d in i: %u\n", byte, *(cp+byte));
    }

    // (v)
    printf("\n(v)???\n");
    for(byte=0; byte<4; byte++) {
        printf("Byte %d in i: %u\n", byte, *(cp+byte)+1);
    }
    printf("i in decimal: %u\n", *ip);
    printf("i in hex: %x\n", *ip);

    // (vi)
    printf("\n(vi)???\n");


    return 0;
}