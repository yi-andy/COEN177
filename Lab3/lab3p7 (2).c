#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
# Name: Andy Yi
# Date:1/24/20
# Title: Lab3 Part 6
# Description: Creates threads
*/

void *go(void *);
#define NTHREADS 10
pthread_t threads[NTHREADS];
int main()
{
    int i;
    for (i = 0; i < NTHREADS; i++)
        pthread_create(&threads[i], NULL, go, (void*)(size_t)i; // passes a pointer to each individual thread which at execution of the thread the pointer points to the size of t
    for (i = 0; i < NTHREADS; i++)
    {
        printf("Thread %d returned\n", i);
        pthread_join(threads[i], NULL);
    }
    printf("Main thread done.\n");
    return 0;
}
void *go(void *arg)
{
    printf("Hello from thread %d with iteration %d\n", (int)pthread_self(), *(int *)arg);
    return 0;
}
