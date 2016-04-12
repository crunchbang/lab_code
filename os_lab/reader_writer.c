#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

pthread_rwlock_t buf_lock = PTHREAD_RWLOCK_INITIALIZER;
int buffer[5] = {1, 2, 3, 4, 5};
int SIZE = 5;

void *reader(void *arg) 
{
    while (1) {
        pthread_rwlock_rdlock(&buf_lock);
        printf("Reader%d: LOCK ACQUIRED\n", *(const int *)arg); 
        int i;
        for (i = 0; i < SIZE; ++i)
            printf("%d ", buffer[i]);
        printf("\n");
        printf("Reader%d: LOCK RELEASED\n", *(const int *)arg); 
        pthread_rwlock_unlock(&buf_lock);
        sleep((rand() % 4));
    }

}

void *writer(void *arg) 
{
    while (1) {
        pthread_rwlock_wrlock(&buf_lock);
        printf("WRITE LOCK ACQUIRED\n");
        int index = rand() % SIZE;
        int value = rand() % 100;
        printf("Writer modified index %d to %d\n", index, value);
        buffer[index] = value;
        printf("WRITE LOCK RELEASED\n");
        pthread_rwlock_unlock(&buf_lock);
        sleep((rand() % 4));
    }

}
int main()
{
    pthread_t r1, r2, r3, w1;
    int i1 = 1, i2 = 2, i3 = 3;

    srand(time(NULL));
    pthread_create(&r1, NULL, reader, (void *)&i1);
    pthread_create(&r2, NULL, reader, (void *)&i2);
    pthread_create(&r3, NULL, reader, (void *)&i3);
    pthread_create(&w1, NULL, writer, NULL);

    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(r3, NULL);
    pthread_join(w1, NULL);

    return 0;
}

