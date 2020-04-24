// Name: Andy Yi
// Date: 3/1/20
// Title: Lab assignment 9: Second Chance
// Description: Uses Second Chance algorithm for page replacement

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct
{ //to
    int pageno;
    int index;
} ref_page;

int main(int argc, char *argv[])
{
    int C_SIZE = atoi(argv[1]); //Size of cache passed by user
    ref_page cache[C_SIZE];     //Cache that holes the input from test file
    int faultno = 0;
    int secondC = 0;
    int n;

    for (n = 0; n < C_SIZE; n++)
    { //initialize cache array
        cache[n].pageno = -1;
        cache[n].index = 0;
    }
    //stores input from the text file using another cache
    char cache2[1000];
    int k = 0;

    while (fgets(cache2, 100, stdin))
    {
        int page_num = atoi(cache2);
        int i;
        for (i = 0; i < C_SIZE; i++) // for loop for 1st chance
        {
            if (page_num == cache[i].pageno)
            {
                cache[i].index = 1;
                secondC = 0;
                break;
            }
            if (i == C_SIZE - 1)
            { //if no match, then continue with page fault
                secondC = 1;
            }
        }

        if (secondC == 1) // another for loop to give 2nd chance
        {
            int j;
            for (j = k; j < C_SIZE; j++)
            {
                if (cache[j].index == 1)
                { //if reference bit is 1 skips
                    cache[j].index = 0;
                    k++;
                    if (k == C_SIZE)
                    {
                        k = 0;
                        j = -1;
                    }
                }
                else
                {
                    cache[j].pageno = page_num; //inserts new page into the cache
                    cache[j].index = 0;         // resets cache index
                    faultno++;
                    printf("Page fault on page %d\n", page_num);
                    k++;
                    if (k == C_SIZE) // if k is the cache size, then it wraps back around
                    {
                        k = 0;
                    }
                    break;
                }
            }
        }
    }

    printf("%d Total Page Faults", faultno);
    return 0;
}