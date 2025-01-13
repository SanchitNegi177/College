#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &nums, int low, int high, int &comparisons, int &swaps)
{
    srand(time(0));
    int random_index = low + rand() % (high - low + 1);
    swap(nums[random_index], nums[high]); 
    swaps++;
    int pivot = nums[high];
    int i = (low - 1);

    for (int j = low; j <= high; j++)
    {
        if (nums[j] <= pivot)
        {
            i++;
            swap(nums[i], nums[j]);
            swaps++;
        }
        comparisons++;
    }
    swap(nums[i + 1], nums[high]);
    swaps++;
    return (i + 1);
}

void quickSort(vector<int> &nums, int low, int high, int &comparisons, int &swaps)
{
    if (low < high)
    {
        int pi = partition(nums, low, high, comparisons, swaps);
        quickSort(nums, low, pi - 1, comparisons, swaps);
        quickSort(nums, pi + 1, high, comparisons, swaps);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int comparisons = 0, swaps = 0;
    quickSort(nums, 0, n - 1, comparisons, swaps);

    for (int it : nums)
        cout << it << " ";
    cout << endl;
    cout << "Comparison: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
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