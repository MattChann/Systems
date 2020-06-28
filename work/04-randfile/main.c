#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>

int genRandInt() {
    int fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0) {
		printf("error %d: %s\n", errno, strerror(errno));
		return 0;
	}
    int randomInt;
    if (read(fd, &randomInt, sizeof(int)) < 0) {
        printf("error %d: %s\n", errno, strerror(errno));
		return 0;
    }
    close(fd);
    return randomInt;
}

int main() {
    printf("Generating random numbers:\n");
    int ARRAY_SIZE = 10;
    int randNums[ARRAY_SIZE];
    int i;
    for(i=0; i<ARRAY_SIZE; i++) {
        int randInt = genRandInt();
        printf("\trandom %d: %d\n", i, randInt);
        randNums[i] = randInt;
    }


    printf("\nWriting numbers to file...\n");
    umask(0);
    int fd = open("output", O_RDWR | O_CREAT, 0666);
    if (fd < 0) {
		printf("error %d: %s\n", errno, strerror(errno));
		return 0;
	}
    if (write(fd, &randNums, ARRAY_SIZE * sizeof(int)) < 0) {
        printf("error %d: %s\n", errno, strerror(errno));
		return 0;
    }
    if (close(fd) < 0) {
        printf("error %d: %s\n", errno, strerror(errno));
		return 0;
    }


    printf("\nReading numbers from file...\n");
    int fid = open("output", O_RDONLY);
    if (fid < 0) {
		printf("error %d: %s\n", errno, strerror(errno));
		return 0;
	}
    int buffer[ARRAY_SIZE];
    if (read(fid, &buffer, ARRAY_SIZE * sizeof(int)) < 0) {
        printf("error %d: %s\n", errno, strerror(errno));
		return 0;
    }


    printf("\nVerification that written values were the same:\n");
    for(i=0; i<ARRAY_SIZE; i++) {
        printf("\trandom %d: %d\n", i, buffer[i]);
    }



    close(fid);
    return 0;
}