#include <bits/stdc++.h>
using namespace std;
#define modd 1000000007
#define lli long long
#define vi vector<int>
#define vl vector<lli>
#define vpl vector<pair<lli, lli>>
#define vp vector<pair<int, int>>
#define pb push_back
#define INF 1e18
#define inf 1e9
#define sz(x) ((int)(x).size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fr(i, zz, n) for (int i = zz; i < n; i++)
#define rfr(i, zz, n) for (int i = zz; i > n; i--)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl "\n";
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define input(v)       \
    for (auto &it : v) \
        cin >> it;
#define output(v)     \
    for (auto it : v) \
        cout << it << " ";
#define outputt(v)    \
    for (auto it : v) \
        cout << it.first << " " << it.second << endl;

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

#ifdef ONLINE_JUDGE
#define bug(...)
#else
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
#endif

void solve()
{   
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
