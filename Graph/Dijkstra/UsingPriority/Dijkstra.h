#include<vector>
#include<utility>
#include<queue>

using namespace std;

# define INF 0x3f3f3f3f
typedef pair <int, int> PAIR;

void printShortestPath (int vertices, int edges, vector <PAIR> adjList [1000])
{
    priority_queue <PAIR, vector <PAIR>, greater <PAIR> > pq;
    vector <int> distance (1000, INF);
    int current;

    pq.push (make_pair (0, 1));
    distance [1] = 0;

    while (! pq.empty ())
    {
        current = pq.top ().second;
        pq.pop ();

        vector <PAIR> :: iterator i;
        for (i = adjList [current].begin (); i != adjList [current].end (); i ++)
        {
            PAIR adjacent = (*i);

            if (distance [adjacent.first] > distance [current] + adjacent.second)
            {
                distance [adjacent.first] = distance [current] + adjacent.second;
                pq.push (make_pair (distance [adjacent.first], adjacent.first));
            }
        }
    }
    
    for (int i = 1; i <= vertices; i ++)
    {
        printf ("The shortest distance of source to %d is %d \n",i,distance[i]);
    }
}