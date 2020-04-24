// Name: Andy Yi
// Date: 3/6/20
// Title: Lab assignment 9: Part Three
// Description: Reads a file from beginning to end. Accepts the filename as a parameter. Can take buffer size. Creates a copy file

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
    FILE *infile = fopen(argv[1], "rb");
    FILE *outfile = fopen("output.txt", "wb");

    char buff[atoi(argv[2])];

    while (fread(buff, atoi(argv[2]), 1, infile)){
        fwrite(buff, atoi(argv[2]), 1, outfile); // copying file 
    };

    fclose(infile);
    fclose(outfile);

    return 0;
}
