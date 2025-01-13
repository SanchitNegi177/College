#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector<int> ans;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            ans.push_back(a[i]);
            i++, j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    if (ans.size() == 0)
    {
        cout << "No common element found\n";
    }
    else
    {
        cout << "Common elements are:\n";
        for (auto it : ans)
            cout << it << endl;
    }
}