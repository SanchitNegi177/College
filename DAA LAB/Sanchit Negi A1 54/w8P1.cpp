#include <bits/stdc++.h>
using namespace std;

// Function to print the constructed MST
void printMST(vector<int> &parent, vector<vector<pair<int, int>>> &adj, int V)
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] + 1 << " - " << i + 1 << "\t" << adj[i][parent[i]].second << " \n";
    }
}

// Function to construct and print MST for a graph represented using adjacency list
void primMST(vector<vector<pair<int, int>>> &adj, int V)
{
    // Priority queue to store the edges with weights (min-heap)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialize the key values as infinity
    vector<int> key(V, INT_MAX);

    // To store the parent array which is used to print the MST
    vector<int> parent(V, -1);

    // To keep track of vertices included in MST
    vector<bool> inMST(V, false);

    // Start from the first vertex
    pq.push({0, 0});
    key[0] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if(inMST[u]) continue;
        // Include u in MST
        inMST[u] = true;

        // Traverse all adjacent vertices of u
        for (auto &it : adj[u])
        {
            int v=it.first;
            int weight=it.second;
            // If v is not in MST and weight of u-v is less than the key value of v
            if (!inMST[v] && key[v] > weight)
            {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    // Print the constructed MST
    printMST(parent, adj, V);
}

int main()
{
    int V;
    cin >> V;

    // Adjacency list representation of the graph
    vector<vector<pair<int, int>>> adj(V);

    // Input the adjacency matrix
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            int weight;
            cin >> weight;
            if (weight != 0)
            {
                adj[i].emplace_back(j, weight);
            }
        }
    }

    // Calculate and print the MST
    primMST(adj, V);

    return 0;
}
