// Name: Andy Yi
// Date: 3/6/20
// Title: Lab assignment 9: Part Two
// Description: Reads a file from beginning to end. Accepts the filename as a parameter. Can change the buffer size

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    char *buff;
    FILE *infile = fopen(argv[1], "rb");
    buff = (char *)malloc(sizeof(char));
    while (fread(buff, 1, 1, infile) == 1)
    {
    };
    fclose(infile);
    return 0;
}
