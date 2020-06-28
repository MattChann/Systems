#include <stdio.h>
#include <stdlib.h>

int strlen(char *s) {
    int length;
    for(length=0; s[length] != '\0'; length++) {}
    return length;
}

char *strncpy(char *dest, char *source, int n) {

}
char *strcat(char *dest, char *source);
int strcmp(char *s1, char *s2);
char * strchr(char *s, char c);