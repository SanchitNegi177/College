#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<char> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int freq[26] = {0};
    int maxi = 0;
    for (char c : v)
    {
        freq[c - 'a']++;
        maxi = max(maxi, freq[c - 'a']);
    }

    if (maxi == 1)
    {
        cout << "No Duplicate Present\n";
    }
    else
    {
        for (int i = 0; i < 26; i++)
            if (freq[i] == maxi)
                cout << char(i + 'a') << "-"<< maxi << endl;
    }
    cout<<endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}