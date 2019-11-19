#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <dirent.h>

int main(int argc, char * argv[]) {
    DIR *dirStream;
    char dirString[256];
    if (argc > 1) {
        strcpy(dirString, argv[1]);
    }
    else {
        printf("Please enter a directory to scan in: ");
        fgets(dirString, 200, stdin);
        int i;
        for (i=0; dirString[i] != '\0'; i++) {
            if (dirString[i] == '\n') {
                dirString[i] = '\0';
            }
        }
        printf("\n");
    }
    dirStream = opendir(dirString);
    
    if (dirStream == NULL) {
        printf("error %d: %s\n", errno, strerror(errno));
        return 0;
    }
    printf("Statistics for directory: %s\n", dirString);

    struct dirent *dirEntry;
    long size = 0;
    for (dirEntry = readdir(dirStream); dirEntry != NULL; dirEntry = readdir(dirStream)) {
        size += dirEntry->d_reclen;
    }
    printf("Total Diectory Size: %ld Bytes\n", size);
    rewinddir(dirStream);

    printf("Directories:\n");
    for (dirEntry = readdir(dirStream); dirEntry != NULL; dirEntry = readdir(dirStream)) {
        if (dirEntry->d_type == DT_DIR) {
            printf("\t%s\n", dirEntry->d_name);
        }
    }
    rewinddir(dirStream);

    printf("Regular files:\n");
    for (dirEntry = readdir(dirStream); dirEntry != NULL; dirEntry = readdir(dirStream)) {
        if (dirEntry->d_type != DT_DIR) {
            printf("\t%s\n", dirEntry->d_name);
        }
    }



    closedir(dirStream);
    return 0;
}