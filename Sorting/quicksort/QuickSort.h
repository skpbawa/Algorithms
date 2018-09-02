#include<stdio.h>
#include<stdlib.h>

void quicksort(int* , int , int);
int partition(int* , int , int);
void swap(int* , int , int);

void quicksort(int* arr, int start, int end)
{
    if (start < end)
    {
        int parIndex = partition(arr, start, end);
        quicksort(arr, start, parIndex - 1);
        quicksort(arr, parIndex + 1, end);
    }
}

int partition(int* arr, int start, int end)
{
    //choosing last element as the pivot element
    int partitionedIndex = end;
    int pivot = arr[end];
    int i = start - 1;//index of smaller element 
    int j;
    // see partition algo from geeks for geeks 
    for (j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, end);
    partitionedIndex = i + 1;
    
    return partitionedIndex;
}

void swap(int* arr, int pos1, int pos2)
{
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}