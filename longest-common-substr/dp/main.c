//program to find longest common substring
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LCS.h"

int main()
{
    char str1[] = "forgeeksskeegfor";
    char str2[] = "rofgeeksskeegrof";
    int l1,l2;
    l1 = strlen(str1);
    l2 = strlen(str2);

    int lcs = LCSubstr(str1, str2, l1, l2);
    printf("The LCS for these strings is : \t %d", lcs);
    return 0;
}