#include <bits/stdc++.h>
using namespace std;

bool bfs(int src, vector<vector<int>> &adj, vector<int> &visited)
{
    queue<int> q;
    q.push(src);
    visited[src] = 0; // Start coloring with 0

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int i = 0; i < adj[node].size(); i++)
        {
            if (adj[node][i]) // There's an edge between node and i
            {
                if (visited[i] == -1) // If not visited
                {
                    visited[i] = 1 - visited[node]; // Color with alternate color
                    q.push(i);
                }
                else if (visited[i] == visited[node]) // If the same color as current node
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    vector<int> visited(n, -1);

    bool isBipartite = true;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == -1) // If not visited
        {
            if (!bfs(i, adj, visited))
            {
                isBipartite = false;
                break;
            }
        }
    }

    if (isBipartite)
    {
        cout << "Graph is bipartite\n";
    }
    else
    {
        cout << "Graph is not bipartite\n";
    }

    return 0;
}
