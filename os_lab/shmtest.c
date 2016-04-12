#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>

#define SHMSIZE 27

int shmid;
char *shm;

void shm_read(char *e) {
    shmid = shmget(2009, SHMSIZE, 0);
    shm = shmat(shmid, 0, 0);
    char *t = shm;
    if (t == NULL )
        printf("\n%s Reads <NULL>\n", e);
    else
        printf("\n%sReads <%s>\n", e, t);
    shmdt(shm);
}

void shm_write(char *e) {
    int data;
    printf("Enter data:\n");
    scanf("%d", &data);
    shmid = shmget(2009, SHMSIZE, 0);
    shm = shmat(shmid, 0, 0);
    char *s = shm;
    *s = '\0';
    sprintf(s, "%s%d", s, data);
    printf("\n%s Wrote <%s>\n", e, s);
    shmdt(shm);
}

int main()
{
    int choice = 1;

    shmget(2009, SHMSIZE, 0666 | IPC_CREAT);

    while (1) {
        printf("1 Parent writes\n"
                "2 Parent reads\n"
                "3 Child writes\n"
                "4 Child reads\n"
                "5 quit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                shm_write("Parent");
                break;
            case 2:
                shm_read("Parent");
                break;
            case 3:
                if (fork() == 0) {
                    shm_write("Child");
                }
                else {
                    wait(NULL);
                    break;
                }
            case 4:
                if (fork() == 0) {
                    shm_read("Child");
                }
                else {
                    wait(NULL);
                }
                break;
            default:
                exit(0);
        }
    }
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
