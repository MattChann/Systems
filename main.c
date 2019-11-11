#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int genRandInt() {
    int fd = open("/dev/random", O_RDONLY);
	if (fd < 0) {
		printf("error %d: %s\n", errno, strerror(errno));
		return 0;
	}
    int *buffer;
    if (read(fd, buffer, sizeof(int)) < 0) {
        printf("error %d: %s\n", errno, strerror(errno));
		return 0;
    }
    close(fd);
    return *buffer;
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
    int fd = open("output", O_RDWR | O_CREAT);
    if (fd < 0) {
		printf("error %d: %s\n", errno, strerror(errno));
		return 0;
	}
    if (write(fd, randNums, sizeof(randNums)) < 0) {
        printf("error %d: %s\n", errno, strerror(errno));
		return 0;
    }

    printf("\nReading numbers from file...\n");
    int buffer[ARRAY_SIZE];
    if (read(fd, buffer, sizeof(buffer)) < 0) {
        printf("error %d: %s\n", errno, strerror(errno));
		return 0;
    }

    printf("\nVerification that written values were the same:\n");
    for(i=0; i<ARRAY_SIZE; i++) {
        printf("\trandom %d: %d\n", i, buffer[i]);
    }



    close(fd);
    return 0;
}