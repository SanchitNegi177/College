#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
        cin >> it;

    priority_queue<int, vector<int>, greater<int>> pq(v.begin(), v.end());

    long long ans = 0;
    while (pq.size() != 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        ans += a + b;
        pq.push(a + b);
    }

    cout << ans << endl;

    return 0;
}