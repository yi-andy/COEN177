#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */ 
/* main function with command-line arguments to pass */
/*# Name: Andy Yi 
# Date: 1/17/20
# Title: Lab2 - Example Fork 
# Description: This program shows the fork process. 
*/
int main(int argc, char *argv[]) {

    printf("This is the Parent process %d \n", getpid());
    int i, p1, p2;
    for (i = 1; i < 3; i++) {
        p1 = fork();
        if (p1 != 0) {
            p2 = fork();
        }
        if (p1 != 0 && p2 != 0) {
            break;
        }
        printf("Child pid %d with parent pid %d \n", getpid(), getppid());
    }

    return 0;
}
