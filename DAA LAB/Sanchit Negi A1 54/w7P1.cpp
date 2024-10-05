#include <bits/stdc++.h>
using namespace std;

// Dijkstra's algorithm
vector<int> dijkstra(int n, unordered_map<int, vector<pair<int, int>>> &adj, vector<int> &parent, int src)
{
    vector<int> distances(n, INT_MAX);
    distances[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    // Dijkstra's algorithm
    while (!pq.empty())
    {
        int u = pq.top().second;
        // int dist_u = pq.top().first;
        pq.pop();

        // Iterate through all adjacent nodes of u
        for (auto &edge : adj[u])
        {
            int v = edge.first;
            int weight = edge.second;

            // Relaxation step: Update distance to v if shorter path through u is found
            if (distances[u] + weight < distances[v])
            {
                distances[v] = distances[u] + weight;
                parent[v] = u;
                pq.push({distances[v], v}); // Push updated distance to v into the priority queue
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

    int akshayHouse;cin>>akshayHouse;
    --akshayHouse ;

    vector<int> parent(n, -1);
    vector<int> distances = dijkstra(n, adj, parent, akshayHouse);

    for (int i = 0; i < n; i++)
    {
        display(parent, i);
        cout << " : " << distances[i] << endl;
    }

    return 0;
}
