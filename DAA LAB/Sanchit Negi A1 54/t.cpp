#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x;
    cin >> x;
    vector<int> result;
    while (x > 0)
    {
        if (x & 1)
        {
            if((x&2) == 0)
            {
                result.push_back(1);
            }
            else
            {
                result.push_back(-1);
                x++;
            }
        }
        else
        {
            result.push_back(0);
        }
        x >>= 1;
    }

    cout<<result.size()<<endl;
    for(auto it:result)
        cout<<it<<" ";
    cout<<endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}