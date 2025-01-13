#include <iostream>
#include <vector>

using namespace std;

void DFS(int v, vector<bool> &visited, const vector<vector<int>> &adj)
{
    visited[v] = true;
    cout << v << " ";

    // for(auto neighbour:adj[v])
    for (int i = 0; i < adj[v].size(); ++i)
    {
        if (!visited[adj[v][i]])   //  !visited[neighbour]
        {
            DFS(adj[v][i], visited, adj);
        }
    }
}

int main()
{
    int V = 5; // Number of vertices
    vector<vector<int>> adj(V);

    // Example graph edges
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);

    cout << "DFS starting from vertex 2:" << endl;
    vector<bool> visited(V, false);

    for (int v = 0; v < V; ++v)
    {
        if (!visited[v])
        {
            DFS(v, visited, adj);
        }
    }

    return 0;
}
