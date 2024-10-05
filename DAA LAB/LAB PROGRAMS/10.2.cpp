#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &nums, int l, int m, int r, int &comparisons, int &invCount)
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

}

void mergeSort(vector<int> &nums, int l, int r, int &comparisons, int &invCount)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(nums, l, m, comparisons, invCount);
        mergeSort(nums, m + 1, r, comparisons, invCount);
        merge(nums, l, m, r, comparisons, invCount);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n), v(2);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int comparisons = 0, invCount = 0;
    mergeSort(nums, 0, n - 1, comparisons, invCount);

    for (int it : nums)
        cout << it << " ";
    cout << endl;
    cout << "Comparison: " << comparisons << endl;
    cout << "Inversion: " << invCount << endl;
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
