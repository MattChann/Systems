#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char ** parse_args(char * line);


int main() {
    printf("Testing Outputs:\n");
    char line[32] = "ls -a -l";
    printf("Running parse_args on \"%s\":\n", line);
    char ** args = parse_args(line);
    printf("Running execvp:\n\n");
    execvp(args[0], args);

    return 0;
}


char ** parse_args(char * line) {
    char ** stringArr = malloc(sizeof(char *) * 6);
    char * token = line;
    int i;
    for (i=0; i<6; i++) {
        if (token != NULL)  {
            stringArr[i] = malloc(sizeof(char) * 50);
            strcpy(stringArr[i], strsep(&token, " "));
            printf("\tstringArr[%d]: %s\n", i, stringArr[i]);
        }else {
            stringArr[i] = NULL;
        }
    }

    return stringArr;
}