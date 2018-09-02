#include<stdio.h>
#include<bits/stdc++.h>
#include<set>
#include<vector>
#include<list>
#include<utility>

# define INF 0x3f3f3f3f

using namespace std;

int vertices, edges;
list< pair<int, int> > *adj;

void addEdge(int startVertex, int endVertex, int edgeLength)
{
    adj[startVertex].push_back (make_pair(endVertex, edgeLength));
}

void calShortestPath()
{
    int source = 0;
    set < pair <int, int> > notTraversed;
    vector <int> disFromSource(vertices, INF);

    notTraversed.insert (make_pair(0, source));//first parameter is distance
    disFromSource[source] = 0;

    while (! notTraversed.empty())
    {
        pair <int, int> temp = *(notTraversed.begin ());
        notTraversed.erase (notTraversed.begin());

        int currVertex = temp.second;
        list< pair<int, int> >::iterator i;
        for (i = adj[currVertex].begin(); i != adj[currVertex].end(); i ++)
        {
            if (disFromSource[*i.first] > (disFromSource[currVertex] + *i.second))
            {
                if (disFromSource[*i.first] != INF)
                    notTraversed.erase (find(make_pair(disFromSource[*i.first],*i.first)));
                //updating
                disFromSource[*i.first] = disFromSource[currVertex] + *i.second;
                notTraversed.insert (make_pair(disFromSource[*i.first], *i.first));
            }
        }
    }
}

int main()
{
    int i, startVertex, endVertex, edgeLength;

    printf ("Enter the number of vertices : \n");
    scanf ("%d", & vertices);

    printf ("Enter the number of edges : \n");
    scanf ("%d", & edges);

    printf ("Enter edges in format : 0  1  6 \nwhere 0 = starting vertex, 1 = ending vertex, and 6 = path length \n");
    for (i = 0; i < edges; i ++)
    {
        scanf ("%d %d %d", & startVertex, & endVertex, & edgeLength);
        addEdge (startVertex, endVertex, edgeLength);
    }

    calShortestPath();

    return 0;
}