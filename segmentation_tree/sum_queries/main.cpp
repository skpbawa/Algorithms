#include<stdio.h>
#include<malloc.h>

int ST [400000];

int buildST (int STindex, int nodeStart, int nodeEnd, int *arr)
{
    int mid = (nodeStart + nodeEnd) / 2;

    if (nodeEnd == nodeStart)
        ST [STindex] = arr [nodeStart];
    else
        ST [STindex] = buildST (STindex * 2 + 1, nodeStart, mid, arr) + buildST (STindex * 2 + 2, mid + 1, nodeEnd, arr);

    return ST [STindex];
}

int findSum (int qstart, int qend,int STindex, int nodeStart, int nodeEnd)
{
    int mid = (nodeEnd + nodeStart) / 2;
    if (qstart <= nodeStart && qend >= nodeEnd)
        return ST [STindex];
    else if (qend < nodeStart || qstart > nodeEnd)
        return 0;
    else
        return (findSum (qstart, qend, STindex * 2 + 1, nodeStart, mid) + findSum (qstart, qend, STindex * 2 + 2, mid + 1, nodeEnd));

}

int main ()
{
    //getting input
    int len, q, start, end;
    printf ("\nEnter length of the array : ");
    scanf ("%d",&len);
    int * arr = (int *)malloc(sizeof (int) * len);
    printf ("Enter the array elements :  \n");
    for (int i = 0; i < len; i ++)
        scanf ("%d", (arr + i));
    printf ("Enter the number of queries :  ");
    scanf ("%d", &q);

    //building the segmentation tree for the array :
    buildST (0, 0, len - 1, arr);

    //for each query
    while (q --)
    {
        printf ("Enter query range :   \n");
        scanf ("%d%d", &start, &end);

        printf ("The Sum for your query is :  %d\n", findSum (start, end, 0, 0, len - 1));
    }
}