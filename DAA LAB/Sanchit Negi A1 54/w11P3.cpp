#include <bits/stdc++.h>

using namespace std;

// memoisation
bool solve(vector<int> v, int target, int i, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (i == v.size() || target < 0)
        return false;

    if (dp[i][target] != -1)
        return dp[i][target];

    if (v[i] > target)
        return dp[i][target] = solve(v, target, i + 1, dp);
    else
        return dp[i][target] = solve(v, target - v[i], i + 1, dp) || solve(v, target, i + 1, dp);
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());

    if (sum % 2 == 0)
    {
        long long target = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        cout << (solve(v, target, 0, dp) ? "YES" : "NO") << endl;
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
