#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char ** parse_args(char * line);


int main() {
    char line[100] = "woah-this-is-cool";
    char *s1 = line;
    while (*s1 != '\0') {
        printf("[%s]\n", strsep( &s1, "-" ));
        printf("[%s]\n", s1);
    }
    return 0;
}


char ** parse_args(char * line) {
    return NULL;
}