#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char ** parse_args(char * line);


int main() {
    /* ===TESTING strsep()===
    char line[100] = "woah-this-is-cool";
    char *s1 = line;
    while (*s1 != '\0') {
        printf("[%s]\n", strsep( &s1, "-" ));
        printf("[%s]\n", s1);
    }
     */
    printf("stuff\n");
    char ** args = parse_args("ls -a -l");
    printf("in main: %s\n", args[0]);
    execvp(args[0], args);

    return 0;
}


char ** parse_args(char * line) {
    printf("1\n");
    char ** stringArr = malloc(sizeof(char *) * 6);
    printf("2\n");
    char * token = line;
    printf("3\n");
    int i=0;
    while (*token != '\0') {
        printf("4\n");
        stringArr[i] = malloc(sizeof(char) * 50);
        printf("5\n");
        stringArr[i] = strsep(&token, " ");
        printf("6\n");
        printf("in loop: %s\n", stringArr[i]);
        i++;
    }

    return stringArr;
}