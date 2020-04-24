// Name: Andy Yi
// Date: 3/6/20
// Title: Lab assignment 9: Part One
// Description: Reads a file from beginning to end. Accepts the filename as a parameter

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFERSIZE 10000

int main(int argc, char *argv[])
{ 
	char *buff[BUFFERSIZE];
	FILE *infile = fopen(argv[1], "wb");
	while (fgets(buff, BUFFERSIZE, infile))
	{
	};
	fclose(infile);
	return 0;
}
