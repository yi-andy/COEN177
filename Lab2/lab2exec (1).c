#include <stdio.h>     /* printf, stderr */
#include <sys/types.h> /* pid_t */
#include <unistd.h>    /* fork */
#include <stdlib.h>    /* atoi */
#include <errno.h>     /* errno */

/*
# Name: Andy Yi
# Date: 1/17/20
# Title: Lab2 – Exec() 
# Description: This is the exec function that the child process runs the ls command, 
and that the parent parent process waits until the child process terminates before it exits.
 */

int main(int argc, char *argv[])
{
    pid_t pid;
    int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay

    printf("\nBefore forking.\n");
    pid = fork();
    if (pid == -1)
    {
        fprintf(stderr, "can't fork, error %d\n", errno);
    }
    else if (pid == 0)
    {
        execlp("/bin/ls", "ls", NULL); // ls shows the files in the directory
    }
    else
    {
        wait(NULL);
        printf("Child Complete\n");
        exit(0);
    }

    return 0;
}