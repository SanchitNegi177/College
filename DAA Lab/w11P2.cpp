#include <bits/stdc++.h>

using namespace std;

// memoisation
int solve(vector<int> coin, long long target, int i, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;
    if (i == coin.size() || target < 0)
        return 0;
    if (dp[i][target] != -1)
        return dp[i][target];

    return dp[i][target] = solve(coin, target - coin[i], i, dp) + solve(coin, target, i + 1, dp);
}

// Tabulation
int countWays(int N, vector<int> &coins)
{
    vector<int> dp(N + 1, 0);
    dp[0] = 1;

    for (int coin : coins)
    {
        for (int i = coin; i <= N; ++i)
        {
            dp[i] += dp[i - coin];
        }
    }

    return dp[N];
}

int main()
{
    int n;
    cin >> n;

    vector<int> coin(n);
    for (int i = 0; i < n; ++i)
        cin >> coin[i];
    long long target;
    cin >> target;

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    sort(coin.begin(), coin.end());
    cout << solve(coin, target, 0, dp) << endl;
    return 0;
}
