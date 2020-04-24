#include <stdio.h>     /* printf, stderr */
#include <stdlib.h>    /* atoi */
#include <errno.h>     /* errno */
#include <pthread.h>

/*
# Name: Andy Yi
# Date: 1/17/20
# Title: Lab2 – Thread 
# Description: This is the thread program that runs using threads instead of 2 processes
 */

struct params
{
    int id;
    int n;
};

// separate loop functions which will print out the thread and number with a certain sleep time in between each iteration
void *loopHundred(void *input)
{
    int i;
    for (i = 0; i < 100; ++i)
    {
        printf("Thread %d: %d\n", ((struct params *)input)->id, i);
        usleep(((struct params *)input)->n);
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    printf("Before threading... \n");

    pthread_t thread1, thread2;
    struct params *thread1_ = (struct params *)malloc(sizeof(struct params));
    struct params *thread2_ = (struct params *)malloc(sizeof(struct params));
    // Needed arguments in order to differentiate threads
    thread1_->id = 1;
    thread2_->id = 2;
    thread1_->n = n;
    thread2_->n = n;

    pthread_create(&thread1, NULL, loopHundred, (void *)thread1_);
    pthread_create(&thread2, NULL, loopHundred, (void *)thread2_);
    // Main waits until thread is done with pthread_join
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
