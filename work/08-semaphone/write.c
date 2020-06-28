#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/shm.h>
#include <fcntl.h>

#define SEM_KEY 24602
#define SHM_KEY 24601
#define SEG_SIZE 200
#define FILE_NAME "story"

int main(int argc, char * argv[]) {
    int semd = semget(SEM_KEY, 1, 0);

    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = -1;

    printf("trying to get in\n");
    semop(semd, &sb, 1);
    
    int shmd = shmget(SHM_KEY, SEG_SIZE, 0644);
    if(shmd < 0) {
        printf("error %d: %s\n", errno, strerror(errno));
    }

    char * story;
    story = shmat(shmd, 0, 0);
    printf("Last addition: %s\n", story);
    printf("Your addition: ");
    fgets(story, SEG_SIZE, stdin);
    *strchr(story, '\n') = 0;

    int fd = open(FILE_NAME, O_WRONLY | O_APPEND);
    write(fd, story, SEG_SIZE);
    close(fd);

    shmdt(story);
    sb.sem_op = 1;
    semop(semd, &sb, 1);
    return 0;
}