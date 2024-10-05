#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int target;
    cin >> target;

    map<int, int> mp;

    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (mp[target - v[i]])
        {
            ans.push_back({v[i], target - v[i]});
        }

        mp[v[i]]++;
    }

    if (ans.size() == 0)
    {
        cout << "No valid pair found\n";
    }
    else
    {
        cout << "Valid pair are:\n";
        for (auto it : ans)
            cout << it.first << " " << it.second << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
    return 0;
}