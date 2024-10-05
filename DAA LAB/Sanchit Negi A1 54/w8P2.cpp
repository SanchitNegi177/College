#include <bits/stdc++.h>
using namespace std;

//  kruskal
// Union-Find Data Structure with path compression
vector<int> parent;

// Find function with path compression
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}
// int find(int i)
// {
//     while (parent[i] > 0)
//         i = parent[i];
//     return i;
// }

// Union function without rank
void Union(int x, int y)
{
    int x_parent = find(x);
    int y_parent = find(y);
    if (x_parent != y_parent)
    {
        parent[x_parent] = y_parent;
    }

    // if(abs(parent[x_parent])>abs(parent[y_parent]))
    // {
    //     parent[x_parent]+=parent[y_parent];
    //     parent[y_parent]=x_parent;
    // }
    // else 
    // {
    //     parent[y_parent]+=parent[x_parent];
    //     parent[x_parent]=y_parent;
    // }

    // if (x_root != y_root)
    // {
    //     if (rank[x_root] < rank[y_root])
    //     {
    //         parent[x_root] = y_root;
    //     }
    //     else if (rank[x_root] > rank[y_root])
    //     {
    //         parent[y_root] = x_root;
    //     }
    //     else
    //     {
    //         parent[y_root] = x_root;
    //         rank[x_root]++;
    //     }
    // }
}

// Kruskal's algorithm to find the MST
int kruskal(vector<vector<int>> &edges, int V)
{
    int sum = 0;
    parent.resize(V);

    // Initialize the parent array
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    // Sort edges by their weight
    sort(edges.begin(), edges.end(), [](vector<int> &a, const vector<int> &b)
         { return a[2] < b[2]; });

    // Process edges
    for (const auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];

        // If u and v are in different sets, include this edge in the MST
        if (find(u) != find(v))
        {
            Union(u, v);
            sum += weight;
        }
    }

    return sum;
}
int main()
{
    int V;
    cin >> V;

    vector<vector<int>> edges;
    vector<vector<int>> matrix(V, vector<int>(V));

    // Input the adjacency matrix
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] != 0)
            {
                edges.push_back({i, j, matrix[i][j]});
            }
        }
    }

    // Calculate the sum of weights of edges in the MST
    int ans = kruskal(edges, V);
    cout << "Sum of weights of edges of the Minimum Spanning Tree: " << ans << endl;

    return 0;
}
