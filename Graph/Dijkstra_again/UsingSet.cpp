#include<bits/stdc++.h>

using namespace std;

struct adjNode
{
    int dest;
    int weight;
    struct adjNode *next;
};

struct adjList
{
    struct adjNode *head;
}

struct graph
{
    int vertices;
    struct adjList *array;
};

struct adjNode *createAdjNode (int endVert, int weight)
{
    struct adjNode *newNode = (struct adjNode) malloc (sizeof (adjNode));
    newNode -> dest = endVert;
    newNode -> weight = weight;
    newNode -> next = NULL;

    return newNode;
}

void makeGraph ()
{
    int vert, edges, start, end, weight;
    cout << "Enter the number of vertices : "<< endl;

    cin >> vert;

    struct graph *g1 = (struct graph *) malloc (sizeof (struct graph));
    g1 ->  vertices = vert;
    g1 -> array = (struct adjList *) malloc (sizeof (adjList) * vert);

    for (int i = 0; i < vert; i ++)
    {
        g1 -> array [i] -> head = NULL;
    }

    cout << "Enter the number of edges : \n";
    cin >> edges;

    cout << "Enter the edges one by one : start vertex end vertex weight: "<< endl;
    for (int i = 0; i < edges; i ++)
    {
        cin >> start >> end >> weight;
        struct adjNode *curr = g1 -> array [start] -> head;
        while (curr != NULL)
        {
            curr = curr -> next;
        }

        curr = createAdjNode (end, weight);
    }
}

int main ()
{
    makeGraph ();
}