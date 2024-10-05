#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int start, int V, const vector<vector<int>> &adj)
{
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int v = q.front();
        cout << v << " ";
        q.pop();

        for (int i = 0; i < adj[v].size(); ++i)
        {
            if (!visited[adj[v][i]])
            {
                visited[adj[v][i]] = true;
                q.push(adj[v][i]);
            }
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

    cout << "BFS starting from vertex 2:" << endl;
    BFS(2, V, adj);

    return 0;
}
