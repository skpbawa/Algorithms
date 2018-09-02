//program to implement mergesort algorithm
#include<stdio.h>
#include<stdlib.h>
#include"MergeSort.h"

int main()
{ 
    int length, i;
    int *arr;
    
    //taking input
    printf("Enter length of the array:   ");
    scanf("%d", &length);
    arr = (int*) malloc (sizeof (int) * length);
    printf("Enter the elements of the array:\n");
    for (i = 0; i < length; i++)
    {
        scanf("%d", (arr + i));
    }

    //sorting
    int start = 0, end = length - 1;
    mergeSort(arr, start, end);

    //output
    printf("The sorted array using mergesort is:\t");
    for (i = 0; i < length; i++)
    {
        printf("%d\t", *(arr + i));
    }
}