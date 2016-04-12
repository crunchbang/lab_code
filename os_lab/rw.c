#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
 
 
sem_t mutex;
sem_t wrt;
 
int reader_count = 0;
int reader_name[] = { 1, 2, 3, 4, 5, 6};
int n_readers = 6;
 
void *reader_func(void *n)
{
    int i = *(int *)n;
    sem_wait(&mutex);
    reader_count++;
    if(reader_count==1)
        sem_wait(&wrt);
    sem_post(&mutex);
    printf("reader %d is reading\n", i);
    sleep(rand()%4);
    sem_wait(&mutex);
    reader_count=reader_count-1;
    if(reader_count == 0)
        sem_post(&wrt);
    sem_post(&mutex);
    return n;
}
void *writer_func(void *arg)
{
    printf("writer is waiting\n");
    sem_wait(&wrt);
    printf("writer is writing\n");
    sem_post(&wrt);
    return arg;
}

int main()
{
    int i;
    pthread_t readers[n_readers];
    pthread_t writer;
    if((sem_init(&mutex, 0, 1)) < 0)
        perror("ERROR");
    if((sem_init(&wrt, 0, 1)) < 0)
        perror("ERROR");
    for (i = 0; i < n_readers; ++i)
        pthread_create(&readers[i], NULL, reader_func, &reader_name[i]);
    pthread_create(&writer, NULL, writer_func, NULL);

    for (i = 0; i < n_readers; ++i)
        pthread_join(readers[i],NULL);
    pthread_join(writer, NULL);

    sem_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}

