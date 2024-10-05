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
    while (low <= high) // searching at index 0,2,4,8,16,32,...........->1
    {
        // cout<<v[low]<<endl;

        comparison++;
        if (v[low] == target)
        {
            ok = 1;
            break;
        }
        else if (v[low] > target) // Maybe target is present in between low and high.......->2
        {
            high = low;
            low = 1 << (comparison - 1);
            break;
        }
        else // increment low when target is greater ............->3
        {
            low = 1 << comparison;
        }
    }
    low/=2;

    if (!ok)
    {
        for (int i = low + 1; i <= high; i++) // linear search when target maybe present from 2
        {
            // cout<<v[i]<<endl;
            comparison++;
            if (v[i] == target)
            {
                ok = 1;
                break;
            }
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