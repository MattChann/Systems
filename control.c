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

union semun {
  int              val;    /* Value for SETVAL */
  struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
  unsigned short  *array;  /* Array for GETALL, SETALL */
  struct seminfo  *__buf;  /* Buffer for IPC_INFO
                              (Linux-specific) */
};

int main(int argc, char * argv[]) {
    int semd;
    int v;
    int r;
    int shmd;
    int fd;

    if (argc > 1) {
        if (strcmp(argv[1], "-c") == 0) {
            // creating the semaphore
            semd = semget(SEM_KEY, 1, IPC_CREAT | IPC_EXCL | 0644);
            if (semd == -1) {
                printf("error %d: %s\n", errno, strerror(errno));
                semd = semget(SEM_KEY, 1, 0);
                v = semctl(semd, 0, GETVAL, 0);
                printf("semaphore created\n");
            }
            else {
                union semun us;
                us.val = 1;
                r = semctl(semd, 0, SETVAL, us);
                printf("semaphore created\n");
            }

            // creating the shared memory
            shmd = shmget(SHM_KEY, SEG_SIZE, IPC_CREAT | 0644);
            printf("shared memory created\n");
            
            // creating the file
            fd = open(FILE_NAME, O_CREAT | O_EXCL | O_RDWR | O_TRUNC, 0644);
            if (fd < 0) {
                fd = open(FILE_NAME, O_RDWR | O_TRUNC, 0644);
            }
            close(fd);
            printf("file created\n");
        }
        else if (strcmp(argv[1], "-r") == 0) {
            struct sembuf sb;
            sb.sem_num = 0;
            sb.sem_op = -1;

            printf("trying to get in\n");
            semop(semd, &sb, 1);

            // reading the file
            fd = open(FILE_NAME, O_RDONLY);
            if(fd < 0) {
                printf("error %d: %s\n", errno, strerror(errno));
            }
            printf("The story so far:\n");
            char buffer[SEG_SIZE];
            while(read(fd, buffer, SEG_SIZE) > 0) {
                printf("%s\n", buffer);
            }
            printf("\n");
            close(fd);

            int shmd = shmget(SHM_KEY, SEG_SIZE, 0600);
            int semd = semget(SEM_KEY, 1, 0);

            // removing shared memory
            shmctl(shmd, IPC_RMID, 0);
            printf("shared memory removed\n");

            // removing the file
            remove(FILE_NAME);
            printf("file removed\n");

            // removing the semaphore
            semctl(semd, IPC_RMID, 0);
            printf("semaphore removed\n");
        }
        else if (strcmp(argv[1],"-v") == 0 ) {
            fd = open(FILE_NAME, O_RDONLY);
            if(fd < 0) {
                printf("error %d: %s\n", errno, strerror(errno));
            }
            printf("The story so far:\n");
            char buffer[SEG_SIZE];
            while(read(fd, buffer, SEG_SIZE) > 0) {
                printf("%s\n", buffer);
            }
            printf("\n");
            close(fd);
        }
    }
    return 0;
}