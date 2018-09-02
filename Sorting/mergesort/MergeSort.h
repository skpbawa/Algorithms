//use quicksort for arrays..its efficient.. but merge sort is preferred for linked lists
#include<stdio.h>

void merge(int* arr, int start, int mid, int end)
{
    //storing
    int temp1[end - start + 1],t1 = 0;
    int temp2[end - start + 1], t2 = 0;
    int t1final, t2final;
    int i;
    for (i = start; i <= mid; i++)
    {
        temp1[t1] = *(arr + i);
        t1 ++;
    }
    for (i = mid + 1; i <= end; i++)
    {
        temp2[t2] = *(arr + i);
        t2 ++;
    }
    t1final = t1, t2final = t2;
    t1 = 0, t2 = 0;
    
    //merging
    i = start;
    while ((i <= end) && (t1 < t1final) && (t2 < t2final))
    {
        if (temp1[t1] < temp2[t2])
        {
            *(arr + i) = temp1[t1];
            t1++;
        }
        else
        {
            *(arr + i) = temp2[t2];
            t2++;
        }
        i ++;
    }

    //remaining
    if (t1 >= t1final)
    {
        while (t2 < t2final)
        {
            *(arr + i) = temp2[t2];
            i++;
            t2++;
        }
    }
    if (t2 >= t2final)
    {
        while (t1 < t1final)
        {
            *(arr + i) = temp1[t1];
            i++;
            t1++;
        }
    }
}

void mergeSort(int* arr, int start,int end)
{
    if (start < end)
    {
        int mid = start + ((end - start) / 2);
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

