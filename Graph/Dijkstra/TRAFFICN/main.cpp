#include<stdio.h>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

#define PAIR pair <int, int>
#define INF 0x3f3f3f3f

int vertices, edges, twoWayEdges, source, destination;

vector < PAIR > *adjList;
vector < PAIR > *reverseAdjList;
vector < pair < PAIR , int > > twoWayPaths;

void addEdge (int edgeStart, int edgeEnd, int edgeLength)
{
    adjList [edgeStart].push_back (make_pair (edgeEnd, edgeLength));
}

void addReverseEdge (int edgeStart, int edgeEnd, int edgeLength)
{
    reverseAdjList [edgeEnd].push_back (make_pair (edgeStart, edgeLength));
}

void add2wayEdge (int edgeStart, int edgeEnd, int edgeLength)
{
    twoWayPaths.push_back (make_pair (make_pair (edgeStart, edgeEnd), edgeLength));
}

void dijkstra2graph ()
{
    vector <int> disFromSource (vertices + 1, INF);
    priority_queue < PAIR, vector < PAIR >, greater< PAIR > > activeVertices;

    disFromSource [source] = 0;
    activeVertices.push (make_pair (0, source));

    while (! activeVertices.empty ())
    {
        int vertexOut = activeVertices.top ().second;
        activeVertices.pop ();

        vector < PAIR > :: iterator i;
        for (i = adjList [vertexOut].begin (); i != adjList [vertexOut].end (); i ++ )
        {
            int adjVertex = (*i).first;
            int weight = (*i).second;

            if (disFromSource [adjVertex] > (disFromSource [vertexOut] + weight))
            {
                disFromSource [adjVertex] = (disFromSource [vertexOut] + weight);
                activeVertices.push (make_pair (disFromSource [adjVertex], adjVertex));
            }
        }
    }
}

void dijkstra2Complement ()
{
    vector <int> disFromDestination (vertices + 1, INF);
    priority_queue < PAIR, vector < PAIR >, greater< PAIR > > activeVertices;

    disFromDestination [destination] = 0;
    activeVertices.push (make_pair (0, destination));

    while (! activeVertices.empty ())
    {
        int vertexOut = activeVertices.top ().second;
        activeVertices.pop ();

        vector < PAIR > :: iterator i;
        for (i = reverseAdjList [vertexOut].begin (); i != reverseAdjList [vertexOut].end (); i ++ )
        {
            int adjVertex = (*i).first;
            int weight = (*i).second;

            if (disFromDestination [adjVertex] > (disFromDestination [vertexOut] + weight))
            {
                disFromDestination [adjVertex] = (disFromDestination [vertexOut] + weight);
                activeVertices.push (make_pair (disFromDestination [adjVertex], adjVertex));
            }
        }
    }
}


int main()
{
    int dataSets;
    int i, edgeStart, edgeEnd, edgeLength;

    scanf ("%d", & dataSets);

    while (dataSets --) //for each dataset
    {
        scanf ("%d %d %d %d %d", & vertices, & edges, & twoWayEdges, & source, & destination);
        adjList = new vector < PAIR > [vertices + 1]; 
        
        for (i = 0; i < edges; i ++)
        {
            scanf ("%d %d %d", & edgeStart, & edgeEnd, & edgeLength);

            addEdge (edgeStart, edgeEnd, edgeLength);
            addReverseEdge (edgeStart, edgeEnd, edgeLength);
        }

        for (i = 0; i < twoWayEdges; i ++)
        {
            scanf ("%d %d %d", & edgeStart, & edgeEnd, & edgeLength);

            add2wayEdge (edgeStart, edgeEnd, edgeLength);
        }

        dijkstra2graph ();
        dijkstra2Complement ();

        delete [] adjList;
    }
}