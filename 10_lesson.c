#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /**
     * strcpy - copy a string
     * 
     * char *strcpy(char *dest, const char *src);
     */
    printf("---strcpy---\n");
    char src[12] = "Hello World";
    char dest[15] = "...";
    printf("Initial Source: %s\n", src);
    printf("Initial Destination: %s\n", dest);
    strcpy(dest, src);
    printf("Final Source: %s\n", src);
    printf("Final Destination: %s\n", dest);

    /**
     * strcat - concatenate two strings
     * 
     * char *strcat(char *dest, const char *src);
     */
    printf("\n---strcat---\n");
    strcpy(src, "World");
    strcpy(dest, "Hello ");
    printf("Initial Source: %s\n", src);
    printf("Initial Destination: %s\n", dest);
    strcat(dest, src);
    printf("Final Source: %s\n", src);
    printf("Final Destination: %s\n", dest);

    /**
     * strcmp - compare two strings
     * 
     * int *strcmp(const char *s1, const char *s2);
     */
    printf("\n---strcmp---\n");
    char s1[2] = "b";
    char s2[2] = "a";
    printf("String 1: %s\n", s1);
    printf("String 2: %s\n", s2);
    printf("Comparison: %d\n", strcmp(s1, s2));
    strcpy(s2, "c");
    printf("String 1: %s\n", s1);
    printf("String 2: %s\n", s2);
    printf("Comparison: %d\n", strcmp(s1, s2));

    /**
     * strchr - locate character in string
     * 
     * char *strchr(const char *s, int c);
     */
    printf("\n---strchr---\n");
    char s[12] = "Hello World";
    char c = 'W';
    printf("String: %s\n", s);
    printf("Looking For: %c\n", c);
    char *found = strchr(s, c);
    printf("Found: %s at %d from %d\n", found, *found, *s);



    return 0;
}