#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<utility>

#define PAIR pair<int, int>

using namespace std;

int rows, columns;
int** cost;
map <PAIR, int> minCostToDest;

int findMin (int a, int b, int c)
{
    if (a <= b)
    {
        if (a <= c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    return b;
}

int calcMinPath (int destx, int desty)
{
    pair <int, int> dest = make_pair(destx, desty);
    if (minCostToDest[dest] != 0)
    {
        return minCostToDest[dest];
    }
    if (destx == 0 && desty == 0)
    {
        minCostToDest [dest] = cost [0][0];
        return cost [0][0];
    }
    else if (destx == 0 && desty != 0)
    {
        minCostToDest [dest] = calcMinPath (destx, desty - 1) + cost [destx][desty];
        return minCostToDest [dest];
    }
    else if (destx != 0 && desty == 0)
    {
        minCostToDest [dest] = calcMinPath (destx - 1, desty) + cost [destx][desty];
        return minCostToDest [dest];
    }
    else
    {
        minCostToDest [dest] = findMin (calcMinPath (destx - 1, desty), calcMinPath (destx - 1, desty - 1), calcMinPath (destx, desty - 1)) + cost [destx][desty];
        return minCostToDest [dest];
    }

}

void getInput ()
{
    int i, j;
    printf ("Enter the number of rows and columns in cost matrix : \n");
    scanf ("%d%d", &rows, &columns);

    //allocating memory for cost matrix
    cost = (int**) malloc (sizeof (int*) * rows);
    for (i = 0; i < rows; i ++)
    {
        cost[i] = (int *) malloc (sizeof (int) * columns);
    }

    //getting user input in cost matrix
    printf ("Enter the values in cost matrix rowwise : \n");
    for (i = 0; i < rows; i ++)
    {
        for (j = 0; j < columns; j ++)
        {
            scanf ("%d", &cost[i][j]);
        }
    }

}

int main()
{
    int destx, desty; //for destination x and y ...
    int minPathLength;

    getInput ();

    printf ("Enter the position (m,n) upto which you want minimum path from (0,0) :\n");
    scanf ("%d%d", &destx, &desty);

    minPathLength = calcMinPath (destx, desty);

    printf ("The minimum path length is : %d\n", minPathLength);

    return 0;
}