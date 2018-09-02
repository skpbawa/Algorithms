//program to implement quicksort algorithm
#include<stdio.h>
#include<stdlib.h>
#include"QuickSort.h"

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
    quicksort(arr, start, end);

    //output
    printf("The sorted array using quicksort is:\t");
    for (i = 0; i < length; i++)
    {
        printf("%d\t", *(arr + i));
    }
}