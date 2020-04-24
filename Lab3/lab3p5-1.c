
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/wait.h> 
/*
# Name: Andy Yi
# Date: 1/24/20
# Title: Lab3 - Program 5
# Description: This program creates a pipe to allow producers to communicate with consumers.
*/

// main
int main(int argc,char *argv[]){
   int  fds[2];
   char buff[60];
   int count;
   int i;
   pipe(fds);
   
   if (fork()==0){
       close(fds[0]);
	   printf("Producer message loading...\n");
       char input[60];
       fgets(input, sizeof(input), stdin); // same as scanf
       write(fds[1], input, 23);
       exit(0);
   }
   else if(fork()==0){
       close(fds[1]);
       read(fds[0], buff, 23);
       printf("Consumer receiving message...\n");
       printf("% s", (char*)buff);
    }

    else{     
      close(fds[0]);
      close(fds[1]);
      wait(0);
      wait(0);
   }
return 0;
}
