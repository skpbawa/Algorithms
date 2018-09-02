/***Following is simple recursive implementation of the LCS problem. 
****Time complexity of the above naive recursive approach is O(2^n)
****in worst case and worst case happens when all characters of X and Y mismatch
**** This is a case of overlapping substructure*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int LCSubseq(char*, char*, int, int);
int max(int, int);

int main()
{
    char str1[] = "ABGHN";
    char str2[] = "YZBAHJN";
    int lcs = LCSubseq(str1, str2, strlen(str1), strlen(str2));

    printf("The longest common subsequence is : \t %d", lcs);

    return 0;
}

int LCSubseq(char* str1, char* str2, int l1, int l2)
{
    if (l1 == 0 || l2 == 0)
    {
        return 0;
    }
    if (str1[l1 - 1] == str2[l2 - 1])
    {
        return (LCSubseq(str1, str2, l1 - 1, l2 - 1) + 1);
    }
    else
    {
        return (max(LCSubseq(str1, str2, l1 - 1, l2), LCSubseq(str1, str2, l1, l2 - 1)));
    }
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}