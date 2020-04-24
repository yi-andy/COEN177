#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 
#include <semaphore.h> 
#include <fcntl.h>

#define bufferSize 5
#define NUMCONSUMERS 5
#define NUMPRODUCERS 10

sem_t full; 
sem_t empty; 
sem_t mutex; 
int producerIndex = 0;
int consumerIndex = 0;
int buffer[bufferSize] = {};

pthread_t consumers[NUMCONSUMERS];
pthread_t producers[NUMPRODUCERS];

void *producer(void *);
void *consumer(void *);

int main (int argc, char *argv[]) {
	sem_init(&full, 0, 0);
	sem_init(&empty, 0, bufferSize);
	sem_init(&mutex, 0, 1);
	int i;
	for(i = 0; i < NUMPRODUCERS; i++)
		pthread_create(&producers[i], NULL, consumer, (void *) (size_t) i);
	for(i = 0; i < NUMCONSUMERS; i++)
		pthread_create(&consumers[i], NULL, producer, (void *) (size_t) i);
	// program waits for producer to end, however while(1) will cause the threads never to end
	for(i = 0; i < NUMPRODUCERS; i++)
		pthread_join(producers[i], NULL);
	for(i = 0; i < NUMCONSUMERS; i++)
		pthread_join(consumers[i], NULL);
    return 0;
}

void* producer(void* id) {
	int value;
	do {
		value = (int)rand() % 10;
		sem_wait(&empty);
		sem_wait(&mutex);			
		buffer[producerIndex] = value;
		printf("Producer %d has produced item %d stored at buff index %d.\n", id, value, producerIndex);
		producerIndex = (producerIndex + 1) % bufferSize; // using mod it cycles from values of 0-4
		sem_post(&mutex);
		sem_post(&full);
	} while(1);
}

void* consumer(void * id) {
	int value;
	do {
		sem_wait(&full);
		sem_wait(&mutex);
		value = buffer[consumerIndex];
		printf("Consumer %d has consumed item %d from buff index %d.\n", id, value, consumerIndex);
		consumerIndex = (consumerIndex + 1) % bufferSize;
		sem_post(&mutex);
		sem_post(&empty);
	} while (1);
}
