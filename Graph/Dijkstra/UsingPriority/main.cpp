#include<stdio.h>
#include<utility>
#include<vector>
#include"Dijkstra.h"

using namespace std;

typedef pair <int, int> PAIR;

int vertices, edges;
vector <PAIR> adjList [1000]; //An adjacency list to store pair of ending vertex and weight of the edge...

void addEdge (int startVertex, int endVertex, int weight)
{
    adjList [startVertex].push_back (make_pair (endVertex, weight));
    adjList [endVertex].push_back (make_pair (startVertex, weight));
}

void getInput ()
{
    int startVertex, endVertex, weight;
    printf ("Enter the number of vertices and edges : \n");
    scanf ("%d %d", &vertices, &edges);
    printf ("Enter the edges like shown : <starting vertex>   <ending vertex>   <weight> : \n");
    for (int i = 1; i <= edges; i ++)
    {
        scanf ("%d %d %d", &startVertex, &endVertex, &weight);
        addEdge (startVertex, endVertex, weight);
    }
    printf ("Assuming the starting vertex to be 1, the shortest path is as follows : \n");
}

int main ()
{
    getInput ();

    printShortestPath (vertices, edges, adjList);

    return 0;
}