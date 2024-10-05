#include <bits/stdc++.h>

using namespace std;
// matrix chain multiplication

int matrixChainMemoised(vector<int> &v, int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(dp[i][j], (matrixChainMemoised(v, i, k, dp) + matrixChainMemoised(v, k + 1, j, dp) + v[i - 1] * v[k] * v[j]));
    }
    return dp[i][j];
}

int matrixChainTabulation(vector<int> &v)
{
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // dp[i][i] = 0 for all i, as no multiplication is needed to multiply one matrix
    for (int length = 2; length < n; length++)
    { // length of the chain
        for (int i = 1; i <= n - length; i++)
        {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + v[i - 1] * v[k] * v[j]);
            }
        }
    }

    return dp[1][n - 1];
}

int matrixChainOrder(vector<int> &v)
{
    int n = v.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return matrixChainMemoised(v, 1, n - 1, dp);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;

    cout << "Minimum number of multiplications is " << matrixChainOrder(v) << endl;
    return 0;
}
