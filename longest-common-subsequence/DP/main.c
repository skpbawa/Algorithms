//program to find longest common subsequence using DP in O(m*n) time..
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LCS.h"

int main()
{
    char str1[] = "hello friends";
    char str2[] = "time to say hello to your friends";
    int l1,l2;
    l1 = strlen(str1);
    l2 = strlen(str2);

    int lcs = LCSubseq(str1, str2, l1, l2);
    printf("The LCS for these strings is : \t %d", lcs);
    return 0;
}