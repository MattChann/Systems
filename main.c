#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>

int main() {
    DIR *dirStream = opendir(".");
    if (dirStream == NULL) {
        printf("error %d: %s\n", errno, strerror(errno));
        return 0;
    }
    printf("Statistics for directory: \n");

    struct dirent *dirEntry;
    long size = 0;
    for (dirEntry = readdir(dirStream); dirEntry != NULL; dirEntry = readdir(dirStream)) {
        size += dirEntry->d_reclen;
    }
    rewinddir(dirStream);

    printf("")
    struct dirent *dirEntry;
    for (dirEntry = readdir(dirStream); dirEntry != NULL; dirEntry = readdir(dirStream)) {
        if (dirEntry->d_type == DT_DIR) {
            
        }
    }
    rewinddir(dirStream);

    struct dirent *dirEntry;
    for (dirEntry = readdir(dirStream); dirEntry != NULL; dirEntry = readdir(dirStream)) {
        if (dirEntry->d_type == DT_DIR) {
            
        }
    }




    closedir();
    return 0;
}