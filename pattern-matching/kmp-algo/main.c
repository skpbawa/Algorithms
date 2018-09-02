#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"kmpSearch.h"
#include <time.h>

int main()
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    char *txt = "ABABDABACDABABCABAB";
    char *pat = "ABABCABAB";
    KMPSearch(pat, txt);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken is:   %f",cpu_time_used);
    return 0;
}