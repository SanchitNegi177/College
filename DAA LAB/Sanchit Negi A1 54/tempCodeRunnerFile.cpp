#include <bits/stdc++.h>
using namespace std;
// for directed graph(using bfs)
bool iscycle(unordered_map<int, vector<int>> &adj, int u, vector<bool> visited,vector<bool> &inRecursion)
{
    visited[u] = true;
    inRecursion[u] = true;
    for (int &vec : adj[u])
    {
        // if not visited then we check for cycle in dfs
        if (visited[vec] == false && iscycle(adj, vec, visited, inRecursion))
            return true;
        else if (inRecursion[vec] == true)
            return true;
    }
    inRecursion[u] = false; // revert
    return false;
}
int main()
{
    int n;
    cin >> n;
    unordered_map<int, vector<int>> adj;
    vector<bool> visited(n + 1, false);
    vector<bool> inRecursion(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                adj[i].push_back(j);
            }
        }
    }
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && iscycle(adj, i, visited, inRecursion))
        {
            flag = 1;
            cout << "CYCLE IS PRESENT" << endl;
            return 0;
        }
    }
    if (flag == 0)
    {
        cout << "CYCLE IS NOT PRESENT" << endl;
    }
    return 0;
}