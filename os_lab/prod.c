#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

void producer();
int n=0,item=5;
void consumer();
sem_t full,empty;
main()
{	pthread_t p_thread,c_thread;
	sem_init(&empty,0,1);
	sem_init(&full,0,0);
	pthread_create(&p_thread,NULL,(void *)&producer,NULL);
	pthread_create(&c_thread,NULL,(void *)&consumer,NULL);
	pthread_join(p_thread,NULL);
	pthread_join(c_thread,NULL);
	sem_destroy(&full);
	sem_destroy(&empty);
}
void producer()
{	int i;
	for(i=0;i<item;i++)
	{	sem_wait(&empty);
		n++;
		printf("\nProducer:%d\n",n);
		sem_post(&full);
	}
}
void consumer()
{	int i;
	for(i=0;i<item;i++)
	{	sem_wait(&full);
		n++;
		printf("\nConsumer:%d\n",n);
		sem_post(&empty);
	}
}
