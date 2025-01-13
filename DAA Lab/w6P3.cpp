#include <bits/stdc++.h>
using namespace std;
// for directed graph(using dfs)

vector<int>ans;
bool iscycle(unordered_map<int, vector<int>> &adj, int u, vector<bool> visited,vector<bool> &inRecursion)
{
    visited[u] = true;
    inRecursion[u] = true;
    ans.push_back(u);
    for (int &neighbour : adj[u])
    {
        // if not visited then we check for cycle in dfs
        if (!visited[neighbour] && iscycle(adj, neighbour, visited, inRecursion))
            return true;
        else if (inRecursion[neighbour] == true && count(inRecursion.begin(),inRecursion.end(),1)==adj.size())
        {
            for(auto it:ans) cout<<it<<" ";
            return true;
        }
    }
    inRecursion[u] = false; // revert
    ans.pop_back();
    return false;
}
int main()
{
    int n;
    cin >> n;
    unordered_map<int, vector<int>> adj;
    vector<bool> visited(n + 1, false);
    vector<bool> inRecursion(n + 1, false);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                adj[i].push_back(j);
            }
        }
    }

    for(auto it:adj)
    {
        cout<<it.first<<" :" ;
        for(auto i:it.second)
        {
            cout<<i<<" ";
        }
        cout<<endl;
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