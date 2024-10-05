#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int comparisons = 0, shifts = 0;
    for (int i = 1; i < n; i++) // Insertion Sort
    {
        int key = nums[i];
        int j = i-1;
        while (j >= 0 && nums[j] > key)
        {
            nums[j+1] = nums[j];
            shifts++;
            comparisons++;
            j--;
        }
        nums[j+1] = key;
        shifts++;
    }

    for (int it : nums)
        cout << it << " ";
    cout << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Shifts: " << shifts << endl;
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
