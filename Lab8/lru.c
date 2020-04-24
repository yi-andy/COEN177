// Name: Andy Yi
// Date: 3/1/20
// Title: Lab assignment 8: LRU
// Description: Uses LRU algorithm for page replacement

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct
{ //to
    int pageNum;
    int index;
} ref_page;

int main(int argc, char *argv[])
{
    int C_SIZE = atoi(argv[1]); //Size of cache passed by user
    ref_page cache[C_SIZE];     //Cache that stores pages
    char pageCache[100];        //Cache that holes the input from test file

    int i, j, k;
    int totalFaults = 0; //keeps track of the total page faults
    int oldest = -1;     // contains old recent page

    for (i = 0; i < C_SIZE; i++)
    { //intialize cache array
        cache[i].pageNum = -1;
        cache[i].index = 100;
    }

    while (fgets(pageCache, 100, stdin))
    {
        int page_num = atoi(pageCache); //stores number read from file as an int
        for (i = 0; i < C_SIZE; i++)
        {
            int temp;
            temp = 0;
            oldest = cache[i].index;
            if (page_num == cache[i].pageNum)
            {
                for (j = 0; j < C_SIZE; j++)
                {
                    if (cache[j].index < cache[i].index)
                    {
                        cache[j].index++;
                    }
                }
                cache[i].index = 0;
                printf("Page %d caused a page fault and is inserted at %d\n", page_num, i);
                break;
            }
            if (i == C_SIZE - 1)
            {
                for (k = 0; k < C_SIZE; k++)
                {
                    cache[k].index++;
                }
                for (j = 0; j < C_SIZE; j++)
                {
                    if (oldest < cache[j].index)
                    {
                        oldest = cache[j].index;
                        temp = j;
                    }
                }

                cache[temp].pageNum = page_num;
                cache[temp].index = 0;
                totalFaults++;

                printf("Page %d caused a page fault and is swapped at %d)\n", page_num, temp);
            }
        }
    }
    printf("%d Total Page Faults\n", totalFaults);
    return 0;
}