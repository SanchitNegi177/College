#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &it : v)
        cin >> it;
    int target;
    cin >> target;
    int comparison = 0;
    bool ok = 0;
    for (int it : v)
    {
        comparison++;
        if (it == target)
        {
            ok = 1;
            break;
        }
    }
    if (ok)
    {
        cout << "Present " << comparison << endl;
    }
    else
    {
        cout << "Not Present " << comparison << endl;
    }
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