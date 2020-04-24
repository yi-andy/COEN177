// Name: Andy Yi
// Date: 3/1/20
// Title: Lab assignment 8: FIFO
// Description: Uses FIFO algorithm for page replacement

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct
{
    int pageNum;
} ref_page;

int main(int argc, char *argv[])
{
    int cacheSize = atoi(argv[1]); // size of cache
    ref_page cache[cacheSize];     // cache of pages
    char testCache[100];           //cache of test file
    int i;
    int j = 0;
    int numFaults = 0; // num of page faults
    int oldest = 0;    // oldest page for replacement

    for (i = 0; i < cacheSize; i++)
    {
        cache[i].pageNum = -1;
    }

    while (fgets(testCache, 100, stdin))
    {
        int page_num = atoi(testCache); // Stores number read from file as an int
        for (i = 0; i < cacheSize; i++)
        {
            if (cache[i].pageNum == page_num)
            {
                break;
            }
            else if (i == cacheSize - 1) // means a page fault
            {
                printf("Page %d caused a page fault\n", page_num);
                numFaults++;
                cache[j].pageNum = page_num;
                j++;
                if (j == cacheSize) // resetting counter if equal to cacheSize
                {
                    j = 0;
                }
            }
        }
    }
    printf("%d Total Page Faults", numFaults);
    return 0;
}
