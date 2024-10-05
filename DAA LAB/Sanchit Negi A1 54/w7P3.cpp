#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int shortestPathWithKEdges(vector<vector<int>> graph, int src, int des, int k)
{
    int V = graph.size();
    int sp[V][V][k + 1];

    // Loop for number of edges from 0 to k
    for (int e = 0; e <= k; e++)
    {
        for (int i = 0; i < V; i++) // for source
        {
            for (int j = 0; j < V; j++) // for destination
            {
                // initialize value
                sp[i][j][e] = INF;

                // from base cases
                if (e == 0 && i == j)
                    sp[i][j][e] = 0;
                if (e == 1 && graph[i][j] != INF)
                    sp[i][j][e] = graph[i][j];

                // go to adjacent only when number of edges is more than 1
                if (e > 1)
                {
                    for (int a = 0; a < V; a++)
                    {
                        if (graph[i][a] != INF && i != a && j != a && sp[a][j][e - 1] != INF)
                            sp[i][j][e] = min(sp[i][j][e], graph[i][a] + sp[a][j][e - 1]);
                    }
                }
            }
        }
    }
    return sp[src][des][k];
}

int main()
{
    int V;
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
            graph[i][j] = (graph[i][j] == 0 ? 1e9 : graph[i][j]);
        }
    }

    int source, destination, k;
    cin >> source >> destination >> k;

    int shortestPath = shortestPathWithKEdges(graph, source - 1, destination - 1, k); // 1 based indexing
    if (shortestPath == INF)
    {
        cout << "No path from source to destination with exactly " << k << " edges." << endl;
    }
    else
    {
        cout << "Shortest path from (" << source << " to " << destination << ") with exactly " << k << " edges: " << shortestPath << endl;
    }

    return 0;
}
