#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

pthread_rwlock_t buf_lock = PTHREAD_RWLOCK_INITIALIZER;
char buffer[6]= "hello";
int SIZE = 5;

void *reader(void *arg) 
{
    while (1) {
        printf("Reader %d is waiting for lock\n", *(int *)arg);
        pthread_rwlock_rdlock(&buf_lock);
        printf("Reader %d acquired lock\n", *(int *)arg);
        printf("Reader %d : %s\n", *(int *)arg, buffer);
        pthread_rwlock_unlock(&buf_lock);
        printf("Reader %d released lock\n", *(int *)arg);
        sleep(1);
    }

}

void *writer(void *arg) 
{
    while (1) {
        int index = rand() % 5;
        char c = 'a' + (rand() % 26);
        printf("Writer is waiting\n");
        pthread_rwlock_wrlock(&buf_lock);
        printf("Writer acquired lock\n");
        buffer[index] = c;
        printf("Writer: %s\n", buffer); 
        sleep(1);
        printf("Writer lock released\n");
        pthread_rwlock_unlock(&buf_lock);
        sleep(1);
    }

}
int main()
{
    pthread_t r1, r2, r3, w1;
    int i1 = 1, i2 = 2, i3 = 3;

    srand(time(NULL));
    pthread_create(&w1, NULL, writer, NULL);
    pthread_create(&r1, NULL, reader, (void *)&i1);
    pthread_create(&r2, NULL, reader, (void *)&i2);
    pthread_create(&r3, NULL, reader, (void *)&i3);

    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(r3, NULL);
    pthread_join(w1, NULL);

    return 0;
}
