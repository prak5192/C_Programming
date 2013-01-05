/********************************************************************
 * This program is used to do the binary search in c data structure.
 *******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
enum SearchResult {
     FOUND,
     NOTFOUND
     };
 
const int RANGE     = 300,  // random numbers from 0-299
          ARRAYSIZE = 100;
 
int BinarySearch (int array[], int low, int high, int key, int *count)
{
    if (low>=high)
    {
        return -1;
    }
    else
    {
        int mid = (low + high)/2;
        *count = *count + 1;
        if (key == array[mid])
            return mid;
        else if (key<array[mid])
        {
            return BinarySearch(array, low, mid-1, key, count);
        }
        else
        {
            return BinarySearch(array, mid+1, high, key, count);
        }
    }
}

void BubbleSort (int array[], int datasize)
{
 
    int pass, counter;
    for (pass = 0; pass < datasize-1; pass++)
    {
        for(counter = 0; counter < datasize-pass; counter++)
        {
            if (array[counter + 1] < array[counter])
            {
                Swap (&array[counter],&array[counter+1]);
            }
 
        }
    }
}
 
Swap (int *v1, int *v2)
{
    int temp;
    temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

void FillArray (int array[], int datasize)
{
    int i =0;
    for (i = 0; i<=datasize; i++)
    {
        array[i] = rand() % RANGE;
    }
}
 
enum SearchResult RunTest (int array[], int datasize, int key, int *count)
{
    BubbleSort(array, datasize);
    int low = 0;
    int high = datasize-1;
    int query = BinarySearch(array, low, high, key, count);
    if (query == -1)
        return NOTFOUND;
    else
        return FOUND;
}

void print_array(int array[], int sizeOfData)
{
    int j =0;
    for (j = 0; j<=sizeOfData; j++)
    {
        printf("Item %d is %d\n", j, array[j]);
    }
}
 
int main ()
{
    enum SearchResult result;
    int searchKey;
    int array[ARRAYSIZE];
    int datasize;
    int count;
    char searchRes[20];
 
    srand(time(0));
 
    printf ("DATA SIZE\tSEARCH KEY\t\tFOUND?\n\n");     // to screen
 
 
    for (datasize = 1; datasize<=ARRAYSIZE; datasize++)
    {
 
        searchKey = rand()% RANGE;
        FillArray(array, datasize);
        count=0;
        enum SearchResult result = RunTest (array, datasize, searchKey,&count);
 
        if (result == FOUND)
            strcpy (searchRes,"FOUND    ");
        else
            strcpy (searchRes,"NOT FOUND");
 
        printf ("%d\t\t%d\t\t\t%s\t\t%d\n",datasize,searchKey,searchRes, count); // screen
    }
 
 
    return 0;
}
