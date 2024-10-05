#include <bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int> &nums, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = nums[l + i];
    for (j = 0; j < n2; j++)
        R[j] = nums[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    int invCount = 0;
    int comparisons = 0;

    while (i < n1 && j < n2)
    {
        comparisons++;
        if (L[i] <= R[j])
            nums[k++] = L[i++];
        else
        {
            nums[k++] = R[j++];
            invCount += m - i;
        }
    }
    while (i < n1)
        nums[k++] = L[i++];

    while (j < n2)
        nums[k++] = R[j++];

    return {comparisons, invCount};
}

vector<int> mergeSort(vector<int> &nums, int l, int r)
{
    int invCount = 0;
    int comparisons = 0;
    vector<int> v(2);
    if (l < r)
    {
        int m = l + (r - l) / 2;
        v = mergeSort(nums, l, m);
        comparisons += v[0], invCount += v[1];
        v = mergeSort(nums, m + 1, r);
        comparisons += v[0], invCount += v[1];
        v = merge(nums, l, m, r);
        comparisons += v[0], invCount += v[1];
    }
    return {comparisons, invCount};
}

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n), v(2);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    v = mergeSort(nums, 0, n - 1);

    for (int it : nums)
        cout << it << " ";
    cout << endl;
    cout << "Comparison: " << v[0] << endl;
    cout << "Inversion: " << v[1] << endl;
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
