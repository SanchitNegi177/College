#include <vector>
#include <utility> // for pair
using namespace std;

class Solution {
public:
void dfs(int vertex, int parent, vector<pair<int, int>> graph[], int signalSpeed, vector<int> &dp, int distance)
{
    if (distance != 0 && distance % signalSpeed == 0)
        dp[vertex] = 1;
    for (auto child : graph[vertex])
    {
        if (child.first == parent)
            continue;
        dfs(child.first, vertex, graph, signalSpeed, dp, distance + child.second);
        dp[vertex] += dp[child.first];
    }
}

vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int signalSpeed)
{
    int n = edges.size() + 1;
    vector<int> dp(n + 1, 0);
    vector<int> ans(n, 0);
    vector<pair<int, int>> graph[n + 1];
    for (auto edge : edges)
    {
        graph[edge[0]].push_back({edge[1], edge[2]});
        graph[edge[1]].push_back({edge[0], edge[2]});
    }
    for (int i = 0; i < n; ++i)
    {
        dfs(i, -1, graph, signalSpeed, dp, 0);
        int sum = 0;
        int cnt = 0;
        for (auto child : graph[i])
            sum += dp[child.first];
        for (auto child : graph[i])
            cnt += (sum - dp[child.first]) * dp[child.first];
        ans[i] = cnt / 2;
        for (int j = 0; j < n; ++j)
            dp[j] = 0;
    }
    return ans;
}
};