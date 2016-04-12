#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t buf_lock;

int buffer[2];
int SIZE = 2;
int front = -1, back = -1;
int n_items = 0;

void *producer(void *arg)
{
    while (1) {
        sem_wait(&buf_lock);
        while (n_items == SIZE) {
            sem_post(&buf_lock);
            sleep(1);
        }
        back = (back+1) % SIZE;
        scanf("%d", &buffer[back]);
        n_items++;
        sem_post(&buf_lock);
        sleep(1);
    }
}
void *consumer(void *arg) {
    while(1) {
        sem_wait(&buf_lock);
        while (n_items == 0) {
            sem_post(&buf_lock);
            sleep(1);
        }
        front = (front+1) % SIZE;
        printf("Consumed:%d\n", buffer[front]);
        n_items--; 
        sem_post(&buf_lock);
        sleep(1);
    }
}


int main()
{
    pthread_t tprod, tcons;

    sem_init(&buf_lock, 0, 1);

    printf("Enter elements:\n");
    pthread_create(&tprod, NULL, producer, NULL);
    pthread_create(&tcons, NULL, consumer, NULL);

    pthread_join(tprod, NULL);
    pthread_join(tcons, NULL);

    return 0;
}
