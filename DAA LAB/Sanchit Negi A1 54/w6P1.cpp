#include<bits/stdc++.h>
using namespace std;

bool dfs(int src,int des,vector<vector<int>>adj,vector<bool>&visited)
{
    if(src==des)
        return true;
    
    
    visited[src]=true;
    for(int i=0;i<adj[src].size();i++)
    {
        if(adj[src][i]==1 && !visited[i])
            if(dfs(i,des,adj,visited))
                return true;
    }
    return false;
}


int main()
{
    int n;cin>>n;
    vector<vector<int>>adj(n,vector<int>(n));

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>adj[i][j];

    int src,des;
    cin>>src>>des;
    vector<bool>visited(n,false);

    if(dfs(src-1,des-1,adj,visited))
    {
        cout<<"Path Exists\n";
    }
    else
    {
        cout<<"Path Does not Exists\n";
    }

    return 0;
}