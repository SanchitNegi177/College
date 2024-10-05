#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    map<int, int> mp;
    string ans = "NO";
    for (auto it : v)
    {
        mp[it]++;
        if (mp[it] > n / 2)
            ans = "YES";
    }

    cout << ans << endl;
    sort(v.begin(), v.end());
    if (n % 2 != 0)
        cout << "Median: " << v[n / 2] << endl;
    else
        cout << "Median: " << 1.0 * (v[(n - 1) / 2] + v[n / 2]) / 2.0 << endl;

    return 0;
}
