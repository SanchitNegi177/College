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
    int low = 0, high = n - 1, comparison = 0;
    bool ok = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        comparison++;
        if (v[mid] == target)
        {
            ok = 1;
            break;
        }
        else if (v[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
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