#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <time.h>

int main() {
    struct stat fileInfo;
    if(stat("main.c", &fileInfo) < 0) {
        printf("errno %d: %s\n", errno, strerror(errno));
        return 0;
    }

    
    printf("File Size: %ld\n", fileInfo.st_size);
    printf("File Mode/Permissions: %o\n", fileInfo.st_mode);
    printf("Time of Last Access: %s\n", ctime(&fileInfo.st_atime));

    printf("Human Readable File Size: ");
    int fileSize = fileInfo.st_size;
    int i,j;
    char prefixes[4] = "GMK";
    for(i=30,j=0; i>=0; i-=10,j++) {
        char prefix = prefixes[j];
        if(prefix == '\0') {
            printf("%d B  ", (fileSize/(1 << i)));
        }
        else{
            printf("%d %cB  ", (fileSize/(1 << i)), prefix);
        }
    }
    printf("\n");

    printf("Permissions In ls -l Form: ");
    int mode = fileInfo.st_mode;
    char modes[4] = "rwx";
    int k;
    for(k=8; k>=0; k--) {
        printf(!(mode & (1 << k)) ? "-" : "%c", modes[k % 4]);
    }
    printf("\n");



    return 0;
}