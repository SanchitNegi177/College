#include <bits/stdc++.h>
using namespace std;

// Bellman-Ford algorithm
vector<int> bellmanFord(int n, unordered_map<int, vector<pair<int, int>>> &adj, vector<int> &parent, int src)
{
    vector<int> distances(n, INT_MAX);
    distances[src] = 0;

    // Relax all edges n-1 times
    for (int i = 0; i < n - 1; ++i)
    {
        for (int u = 0; u < n; ++u)
        {
            if (distances[u] == INT_MAX)
                continue;
            for (auto &edge : adj[u])
            {
                int v = edge.first;
                int weight = edge.second;
                if (distances[u] + weight < distances[v])
                {
                    distances[v] = distances[u] + weight;
                    parent[v] = u;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < n; ++u)
    {
        for (auto &edge : adj[u])
        {
            int v = edge.first;
            int weight = edge.second;
            if (distances[u] != INT_MAX && distances[u] + weight < distances[v])
            {
                cout << "Graph contains negative weight cycle" << endl;
                return {};
            }
        }
    }

    return distances;
}

void display(vector<int> parent, int i)
{
    if (parent[i] == -1)
    {
        cout << i + 1 << " ";
        return;
    }
    display(parent, parent[i]);
    cout << i + 1 << " ";
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    // Assuming input is adjacency list with weights (distances)
    unordered_map<int, vector<pair<int, int>>> adj;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (graph[i][j] != 0)
                adj[i].push_back({j, graph[i][j]});

    vector<int> parent(n, -1);
    int akshayHouse;
    cin >> akshayHouse;
    --akshayHouse;
    // Run Bellman-Ford algorithm from Akshay's house
    vector<int> distances = bellmanFord(n, adj, parent, akshayHouse);

    // Print shortest distances from Akshay's house to all locations
    for (int i = 0; i < n; i++)
    {
        display(parent, i);
        cout << " : " << distances[i] << endl;
    }

    return 0;
}

/*
struct Edge
{
    int src, dest, weight;
};

void BellmanFord(int V, int E, Edge edges[], int src)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i <= V - 1; ++i)
    {
        for (int j = 0; j < E; ++j)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }
}
*/