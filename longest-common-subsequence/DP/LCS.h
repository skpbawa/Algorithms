int max(int a, int b)
{
    return (a > b) ? a : b;
}

void DP(char* str1, char* str2, int l1, int l2, int** lengths)
{
    int i, j;
    for (i = 0; i <= l1; i++)
    {
        for (j = 0; j <= l2; j++)
        {
            if (i == 0 || j == 0)
            {
                lengths[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1]) //i-1 and j-1 bcoz one row and one col has zeros..so i=1 and j=1 se kaam strt ho rha
            {
                lengths[i][j] = lengths[i - 1][j - 1] + 1;    
            }
            else
            {
                lengths[i][j] = max(lengths[i - 1][j], lengths[i][j - 1]);
            }
        }
    }

}

int LCSubseq(char* str1, char *str2, int l1, int l2)
{
    int **lengths;
    int i, j;
    lengths = (int **) malloc (sizeof(int*) * (l1 + 1)); 
    // l1+1 because we want to use DP..first row nd first column should contain 0..! trick !
    for (i = 0; i < l1 + 1; i ++)
    {
        lengths[i] = (int *) malloc (sizeof(int) * (l2 + 1));
    }

    //storing the LCSubstrings in array
    DP(str1, str2, l1, l2, lengths);

    return lengths[l1][l2];
}