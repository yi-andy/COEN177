// Name: Andy Yi
// Date: 3/6/20
// Title: Lab assignment 9: Part Four
// Description: Reads a file from beginning to end. Accepts the filename as a parameter. Can take buffer size. Creates multiple copies of the file using threads.


#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

char input_name[20];
int BUFSIZE;

void *go(void *arg)
{
    FILE *infile;
    FILE *outfile;
    char output_name[20];
    char buffer[BUFSIZE];

    sprintf(output_name, "output%d.txt", (int)arg);

    infile = fopen(input_name, "r");
    outfile = fopen(output_name, "w");

    while (fread(buffer, sizeof(char), 1, infile) > 0)
    {
        ;
        fwrite(buffer, sizeof(char), 1, outfile);
    }
    fclose(infile);
    fclose(outfile);

    return NULL;
}

int main(int argc, char *argv[])
{
    BUFSIZE = atoi(argv[2]);
    int NTHREADS = atoi(argv[3]);
    int i;

    pthread_t threads[NTHREADS];
    strcpy(input_name, argv[1]);

    for (i = 0; i < NTHREADS; i++)
    {
        pthread_create(&threads[i], NULL, go, (void *)(size_t)i);
    }
    for (i = 0; i < NTHREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
